#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_set>
using namespace std;
using ll = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


int solve()
{
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    UnionFind uf(H*W);
    for(int i = 0;i < H;i++){
        for(int j = 0;j+1 < W;j++){
            if (G[i][j] == '.' && G[i][j+1] == '.'){
                uf.unite(W*i+j,W*i+j+1);
            }
        }
    }
    for(int i = 0;i+1 < H;i++){
        for(int j = 0;j < W;j++){
            if (G[i][j] == '.' && G[i+1][j] == '.'){
                uf.unite(W*i+j,W*(i+1)+j);
            }
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if (G[i][j] == 'S'){
                vector<pair<ll,ll>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
                // cout << "!" << endl;
                for(int k = 0;k < 4;k++){
                    for(int l = k+1;l<4;l++){

                        ll next1_x = i+ directions[k].first;
                        ll next1_y = j+ directions[k].second;
                        ll next2_x = i+ directions[l].first;
                        ll next2_y = j+ directions[l].second;
                        if (0 <= next1_x && next1_x < H &&
                            0 <= next1_y && next1_y < W &&
                            0 <= next2_x && next2_x < H &&
                            0 <= next2_y && next2_y < W
                        ){
                            if (uf.same(W*next1_x+next1_y,W*next2_x+next2_y)){
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
