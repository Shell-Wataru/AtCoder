// https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

template< typename G >
struct DoublingLowestCommonAncestor {
  const int LOG;
  vector< int > dep;
  const G &g;
  vector< vector< int > > table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
    table.assign(LOG, vector< int >(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to : g[idx]) {
      if(to != par) dfs(to, idx, d + 1);
    }
  }

  void build(ll root) {
    dfs(root, -1, 0);
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }

  int distance(int u, int v) {
    ll c = query(u,v);
    return dep[u]+dep[v]- 2*dep[c];
  }

  int ancestor(int u, int k) {
    for(int i = LOG - 1; i >= 0; i--) {
      if((k >> i) & 1) u = table[i][u];
    }
    return u;
  }
};

int main(){
    vector<vector<ll>> G = {
        {1,2},
        {0,3,4},
        {0,5,6},
        {1},
        {1},
        {2},
        {2}
    };
    DoublingLowestCommonAncestor<vector<vector<ll>>> lca(G);
    lca.build();
    cout << lca.query(0,0) << endl;
    cout << lca.query(1,2) << endl;
    cout << lca.query(3,4) << endl;
    cout << lca.query(5,6) << endl;
    cout << lca.query(3,5) << endl;
    return 0;
}