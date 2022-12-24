#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

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

  int ancestor(int u, int k) {
    for(int i = LOG - 1; i >= 0; i--) {
      if((k >> i) & 1) u = table[i][u];
    }
    return u;
  }

  int distance(int u, int v) {
    ll c = query(u,v);
    return dep[u]+dep[v]- 2*dep[c];
  }
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  vector<vector<ll>> G(n);
  for(int i = 0;i < n-1;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DoublingLowestCommonAncestor<vector<vector<ll>>> lca(G);
  lca.build(0);
  vector<vector<pair<ll,ll>>> d_pairs(n);
  for(int i = 0;i < n;i++){
    for(int j = i;j < n;j++){
      d_pairs[lca.distance(i,j)].push_back({i,j});
    }
  }
  vector<vector<ll>> DP(n,vector<ll>(n,0));
  for(int i = 0;i < n;i++){
    for(auto p:d_pairs[i]){
      if (i == 0){
        DP[p.first][p.second] = 1;
      }else if (i == 1){
        if (S[p.first] == S[p.second]){
          DP[p.first][p.second] = 2;
          DP[p.second][p.first] = 2;
        }else{
          DP[p.first][p.second] = 1;
          DP[p.second][p.first] = 1;
        }
      }else{
        ll c = lca.query(p.first,p.second);
        ll parent1,parent2;
        if (c == p.first){
          parent1 = lca.ancestor(p.second,i-1);
          parent2 = lca.ancestor(p.second,1);
        }else if (c == p.second){
          parent1 = lca.ancestor(p.first,1);
          parent2 = lca.ancestor(p.first,i-1);
        }else{
          parent1 = lca.ancestor(p.first,1);
          parent2 = lca.ancestor(p.second,1);
        }
        if (S[p.first] == S[p.second]){
          DP[p.first][p.second] = DP[parent1][parent2]+2;
          DP[p.second][p.first] = DP[parent1][parent2]+2;
        }else{
          DP[p.first][p.second] = max(DP[parent1][p.second],DP[p.first][parent2]);
          DP[p.second][p.first] = max(DP[parent1][p.second],DP[p.first][parent2]);
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      ans = max(ans,DP[i][j]);
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
