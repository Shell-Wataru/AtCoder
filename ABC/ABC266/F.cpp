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
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

template< typename G >
struct LowLink {
  const G &g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;

  LowLink(const G &g) : g(g) {}

  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }

  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
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

int set_parent(UnWeightedGraph &undirectedG,vector<int> &comp,ll circle_comp,ll current,vector<bool> &visited,vector<ll> &parents,ll parent){
  visited[current] = true;
  parents[current] = parent;
  for(auto to:undirectedG[current]){
    if (!visited[to]){
      if (comp[current] == circle_comp){
        if (comp[to] == circle_comp){
          set_parent(undirectedG,comp,circle_comp,to,visited,parents,parent);
        }else{
          set_parent(undirectedG,comp,circle_comp,to,visited,parents,current);
        }
      }else{
        set_parent(undirectedG,comp,circle_comp,to,visited,parents,parent);
      }

    }
  }
  return 0;
}

int solve()
{
  ll N;
  cin >> N;
  UnWeightedGraph undirectedG(N);
  UnWeightedGraph directedG(N);
  for(int i = 0;i < N;i++){
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    undirectedG[u].push_back(v);
    undirectedG[v].push_back(u);
  }
  TwoEdgeConnectedComponents<UnWeightedGraph> tecc(undirectedG);
  vector<vector<int>> zippedG;
  tecc.build(zippedG);
  vector<ll> comp_count(zippedG.size());
  for(auto c:tecc.comp){
    comp_count[c]++;
  }
  vector<bool> in_circle(zippedG.size());
  vector<bool> visited(N,false);
  ll root = -1;
  for(int i = 0;i < zippedG.size();i++){
    in_circle[i] = comp_count[i] > 1;
  }
  for(int i = 0;i < N;i++){
    if (in_circle[tecc.comp[i]]){
      root = i;
      break;
    }
  }
  vector<ll> parents(N,-1);
  set_parent(undirectedG,tecc.comp,tecc.comp[root],root,visited,parents,-1);
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll x,y;
    cin >> x >> y;
    x--;
    y--;
    ll parent_x = parents[x];
    ll parent_y = parents[y];
    if (parent_x > parent_y){
      swap(x,y);
      swap(parent_x,parent_y);
    }
    if ( (parent_x == -1  && x == parent_y) || (parent_x != -1 && (parent_x == parent_y) )){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
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
