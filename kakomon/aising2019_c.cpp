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

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<string> G(N);
    UnionFind uf(N*M);
    vector<pair<ll,ll>> direction = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1},
    };
    for (size_t i = 0; i < N; i++)
    {
        cin >> G[i];
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            for(auto &p:direction){
                ll next_i = i + p.first;
                ll next_j = j + p.second;
                if (0 <= next_i && next_i < N && 0 <= next_j && next_j < M){
                    if ((G[i][j] == '#' && G[next_i][next_j] == '.') || (G[i][j] == '.' && G[next_i][next_j] == '#')){
                        uf.unite(M*i+j,M*next_i + next_j);
                    }
                }
            }
        }
    }
    vector<ll> black_count(N*M);
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if (G[i][j] == '#'){
                black_count[uf.find(M*i+j)]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if (uf.find(M*i+j) == M*i+j){
                // cout << uf.size(M*i+j) << "," << black_count[M*i+j] << endl;
                ans += (uf.size(M*i+j) -  black_count[M*i+j])*black_count[M*i+j];
            }
        }
    }
    cout << ans << endl;
   return 0;
}