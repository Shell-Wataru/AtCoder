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
namespace mp = boost::multiprecision;

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

template <typename G>
struct LowLink
{
  const G &g;
  vector<int> used, ord, low;
  vector<int> articulation;
  vector<pair<int, int>> bridge;

  LowLink(const G &g) : g(g) {}

  int dfs(int idx, int k, int par)
  {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for (auto &to : g[idx])
    {
      if (!used[to])
      {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if (ord[idx] < low[to])
          bridge.emplace_back(minmax(idx, (int)to));
      }
      else if (to != par)
      {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if (is_articulation)
      articulation.push_back(idx);
    return k;
  }

  virtual void build()
  {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for (int i = 0; i < g.size(); i++)
    {
      if (!used[i])
        k = dfs(i, k, -1);
    }
  }
};

template< typename G >
struct TwoEdgeConnectedComponents : LowLink< G > {
  using LL = LowLink< G >;
  vector< int > comp;

  TwoEdgeConnectedComponents(const G &g) : LL(g) {}

  int operator[](const int &k) {
    return comp[k];
  }

  void dfs(int idx, int par, int &k) {
    if(~par && this->ord[par] >= this->low[idx]) comp[idx] = comp[par];
    else comp[idx] = k++;
    for(auto &to : this->g[idx]) {
      if(comp[to] == -1) dfs(to, idx, k);
    }
  }

  void build(G &t) {
    LL::build();
    comp.assign(this->g.size(), -1);
    int k = 0;
    for(int i = 0; i < comp.size(); i++) {
      if(comp[i] == -1) dfs(i, -1, k);
    }
    t.resize(k);
    for(auto &e : this->bridge) {
      int x = comp[e.first], y = comp[e.second];
      t[x].push_back(y);
      t[y].push_back(x);
    }
  }
};

int main()
{
  // 整数の入力
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> G(N);
  vector<vector<ll>> DFSTree;
  for (ll i = 0; i < M; i++)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  TwoEdgeConnectedComponents<vector<vector<ll>>> tecc(G);
  tecc.build(DFSTree);
  DoublingLowestCommonAncestor<vector<vector<ll>>> lca(DFSTree);
  lca.build();
  ll Q;
  cin >> Q;
  for (ll i = 0; i < Q; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;
    a = tecc[a];
    b = tecc[b];
    c = tecc[c];
    ll lca_ab = lca.query(a,b);
    ll lca_bc = lca.query(b,c);
    ll lca_ca = lca.query(c,a);
    if (lca_ca == a){
      if (lca_bc == b && lca_ab == a){
        cout << "OK" <<endl;
      }else{
        cout << "NG" << endl;
      }
    }else if(lca_ca == c){
      if (lca_bc == c && lca_ab == b){
        cout << "OK" <<endl;
      }else{
        cout << "NG" << endl;
      }
    }else{
      if ((lca_ab == b || lca_bc == b) && (lca_ab == lca_ca || lca_bc == lca_ca)){
        cout << "OK" <<endl;
      }else{
        cout << "NG" << endl;
      }
    }

  }

  return 0;
}