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
  void reset(){
      fill(data.begin(),data.end(),-1);
  }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    vector<pair<ll,ll>> Edges(M);
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = true;
        G[v][u] = true;
        Edges[i] = {u,v};
    }
    ll ans = 0;
    UnionFind uf_normal(N);
    UnionFind uf_bipartile(2*N);
    for(int i = 0;i < 1ll<<(N-1);i++){
        bool is_ok = true;
        ll target = i+ (1ll<<(N-1));
        for(int j = 0;j < N;j++){
            if (!(target & 1ll<<j)){
                continue;
            }
            for(int k = j+1;k<N;k++){
                if ((target & 1ll<<k) && G[j][k] ){
                    is_ok = false;
                    break;
                }
            }
        }
        if (!is_ok){
            continue;
        }
        // cout << target << endl;
        ll current = 3;
        uf_normal.reset();
        uf_bipartile.reset();
        for(auto &e:Edges){
            if ( (target & 1ll<<e.first) || (target & 1ll<<e.second)){
                continue;
            }
            uf_normal.unite(e.first,e.second);
            uf_bipartile.unite(2*e.first,2*e.second+1);
            uf_bipartile.unite(2*e.first+1,2*e.second);
        }
        bool is_bipartile = true;
        for(int j = 0;j < N;j++){
            if (uf_bipartile.same(2*j,2*j+1)){
                is_bipartile = false;
                break;
            }
        }
        if (is_bipartile){
            for(int j = 0;j < N;j++){
                if (!(target & 1ll<<j) && uf_normal.find(j) == j){
                    current *= 2;
                }
            }
            ans += current;
        }
    }
    cout << ans << endl;
    return 0;
}
