#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

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

vector<pair<ll,ll>> directions = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
int solve()
{
    ll H,W;
    cin >> H >> W;
    ll Q;
    cin >> Q;
    vector<bool>  colors(H*W,false);
    UnionFind uf(H*W);
    for(int i = 0;i < Q;i++){
        ll t;
        cin >> t;
        if (t == 1){
            ll r,c;
            cin >> r >> c;
            r--;
            c--;
            colors[W*r+c] = true;
            for(auto d:directions){
                ll next_r = r + d.first;
                ll next_c = c + d.second;
                if (0 <= next_r && next_r < H &&
                    0 <= next_c && next_c < W
                ){
                    if (colors[W*next_r + next_c]){
                        uf.unite(W*next_r + next_c,W*r + c);
                    }
                }
            }
        }else{
            ll r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;
            if (colors[W*r1 + c1] && colors[W*r2 + c2] && uf.same(W*r1 + c1,W*r2 + c2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}