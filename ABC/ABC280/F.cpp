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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

// Lowest Common Ancestor by binary lifting
// https://youtu.be/8uowVvQ_-Mo?t=4306
template<typename T> // T: type of cost
struct lca {
  int n, root, l;
  vector<vector<int>> to;
  vector<vector<T>> co;
  vector<int> dep;
  vector<T> costs;
  vector<vector<int>> par;
  lca(int n):n(n),to(n),co(n),dep(n),costs(n) {
    l = 0;
    while ((1<<l) < n) ++l;
    par = vector<vector<int>>(n+1,vector<int>(l,n));
  }
  void addEdge(int a, int b, T c=0) {
    to[a].push_back(b); co[a].push_back(c);
    to[b].push_back(a); co[b].push_back(c);
  }
  void dfs(int v, int d=0, T c=0, int p=-1) {
    if (p != -1) par[v][0] = p;
    dep[v] = d;
    costs[v] = c;
    for (int i = 0; i < to[v].size(); ++i) {
      int u = to[v][i];
      if (u == p) continue;
      dfs(u, d+1, c+co[v][i], v);
    }
  }

  void init(int _root=0) {
    root = _root;
    dfs(root);
    for (int i = 0; i < l-1; ++i) {
      for (int v = 0; v < n; ++v) {
        par[v][i+1] = par[par[v][i]][i];
      }
    }
  }
  // LCA
  int ancestor(int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);
    int gap = dep[b]-dep[a];
    for (int i = l-1; i >= 0; --i) {
      int len = 1<<i;
      if (gap >= len) {
        gap -= len;
        b = par[b][i];
      }
    }
    if (a == b) return a;
    for (int i = l-1; i >= 0; --i) {
      int na = par[a][i];
      int nb = par[b][i];
      if (na != nb) a = na, b = nb;
    }
    return par[a][0];
  }
  int length(int a, int b) {
    int c = ancestor(a,b);
    return dep[a]+dep[b]-dep[c]*2;
  }
  T dist(int a, int b) {
    int c = ancestor(a,b);
    return costs[b]-costs[a];
  }
};

struct UnionFind
{
  vector<int> data;
  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if (x == y)
    {
      return (false);
    }
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y)
  {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k)
  {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

bool dfs(vector<vector<pair<ll, ll>>> &G,ll current,ll cost,lca<ll> &ca,vector<ll> &costs,vector<bool> &visited){
  if (visited[current]){
    if (costs[current] == cost){
      return false;
    }else{
      return true;
    }
  }
  costs[current] = cost;
  visited[current] = true;
  bool cycle = false;
  for(auto e:G[current]){
    ll to = e.first;
    ll d = e.second;
    if (!visited[to]){
      ca.addEdge(current,to,d);
    }
    cycle = cycle || dfs(G,to,cost+d,ca,costs,visited);
    if (cycle){
      return true;
    }
  }
  return cycle;
}
int main()
{
  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<pair<ll, ll>>> G(N);
  UnionFind uf(N);
  for (int i = 0; i < M; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back({b, c});
    G[b].push_back({a, -c});
    uf.unite(a, b);
  }
  lca<ll> calculator(N+1);
  vector<ll> costs(N,numeric_limits<ll>::min());
  vector<bool> visited(N,false);
  vector<bool> has_cycle(N,false);
  for (int i = 0; i < N; i++)
  {
    if (uf.find(i) == i)
    {
      has_cycle[i] = dfs(G,i,0,calculator,costs,visited);
      calculator.addEdge(N,i,0);
    }
  }
  calculator.init(N);
  for (int i = 0; i < Q; i++)
  {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    if (!uf.same(x, y))
    {
      cout << "nan" << endl;
    }
    else if (has_cycle[uf.find(x)])
    {
      cout << "inf" << endl;
    }
    else
    {
      cout << calculator.dist(x,y) << endl;
    }
  }
  return 0;
}
