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
#include <set>
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

  void build() {
    dfs(0, -1, 0);
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
};

int solve()
{
  ll N;
  cin >> N;
  vector<vector<ll>> G(N);
  for(int i = 0;i < N-1;i++){
      ll x,y;
      cin >> x>> y;
      x--;y--;
      G[x].push_back(y);
      G[y].push_back(x);
  }
  DoublingLowestCommonAncestor<vector<vector<ll>>> lca(G);
  lca.build();
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
      ll x,y;
      cin >> x >> y;
      x--;y--;
      ll z = lca.query(x,y);
      cout << - 2 * lca.dep[z] + lca.dep[x] + lca.dep[y] + 1 << endl;
  }
  return 0;
}

int main()
{
  // ll T;
  // cin >> T;
  // for (int i = 0; i < T; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
