#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

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

template <typename G>
struct StronglyConnectedComponents
{
  const G &g;
  UnWeightedGraph gg, rg;
  vector<int> comp, order, used;
  vector<vector<ll>> nodes;
  vector<vector<ll>> edges;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size())
  {
    for (int i = 0; i < g.size(); i++)
    {
      for (auto e : g[i])
      {
        gg[i].emplace_back((int)e);
        rg[(int)e].emplace_back(i);
      }
    }
    build();
  }

  int operator[](int k)
  {
    return comp[k];
  }

  void dfs(int idx)
  {
    if (used[idx])
      return;
    used[idx] = true;
    for (int to : gg[idx])
      dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt)
  {
    if (comp[idx] != -1)
      return;
    comp[idx] = cnt;
    for (int to : rg[idx])
      rdfs(to, cnt);
  }

  void build()
  {
    for (int i = 0; i < gg.size(); i++)
      dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for (int i : order)
      if (comp[i] == -1)
        rdfs(i, ptr), ptr++;

    edges.resize(ptr);
    nodes.resize(ptr);
    for (int i = 0; i < g.size(); i++)
    {
      for (auto &to : g[i])
      {
        int x = comp[i], y = comp[to];
        if (x == y)
          continue;
        edges[x].push_back(y);
      }
    }
    for (int i = 0; i < g.size(); i++)
    {
      nodes[comp[i]].push_back(i);
    }
  }
};

int solve()
{
  ll n;
  cin >> n;
  UnWeightedGraph g(n);
  string s;
  cin >> s;
  for (size_t i = 0; i < n; i++)
  {
    if (s[i] == '>')
    {
      g[i].push_back((i + 1) % n);
    }
    else if (s[i] == '<')
    {
      g[(i + 1) % n].push_back(i);
    }
    else
    {
      g[i].push_back((i + 1) % n);
      g[(i + 1) % n].push_back(i);
    }
  }
  StronglyConnectedComponents<UnWeightedGraph> scc(g);
  ll ans = 0;
  for (auto &components : scc.nodes)
  {
    if (components.size() > 1)
    {
      ans += components.size();
    }
  }
  cout << ans << endl;
  return 0;
}
int main()
{
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  return 0;
}
