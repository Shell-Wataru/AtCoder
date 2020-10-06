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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

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

int main()
{
  ll N, M, K;
  cin >> N >> M >> K;
  UnWeightedGraph G(N);
  vector<char> C(N);
  for (int i = 0; i < N; i++)
  {
    cin >> C[i];
  }

  for (int i = 0; i < M; i++)
  {
    ll from, to;
    cin >> from >> to;
    from--;
    to--;
    G[from].push_back(to);
  }
  StronglyConnectedComponents<UnWeightedGraph> scc(G);
  vector<vector<string>> DP(scc.nodes.size(), vector<string>(K + 1, "絶"));
  for (int i = scc.nodes.size() - 1; i >= 0; i--)
  {
    vector<char> chars;
    for (auto from : scc.nodes[i])
    {
      // cout << from;
      chars.push_back(C[from]);
    }
    // cout << endl;
    sort(chars.begin(), chars.end());
    DP[i][0] = "";
    vector<string> strings;
    strings.push_back("");
    for (int j = 1; j <= min((ll)chars.size(),K); j++)
    {
      strings.push_back(strings.back() + chars[j - 1]);
      DP[i][j] = strings.back();
      // cout << strings.back() << endl;
    }
    set<int> edges(scc.edges[i].begin(), scc.edges[i].end());
    for (auto to : edges)
    {
      for (int j = 0; j < strings.size(); j++)
      {
        for (int k = 0; k <= K; k++)
        {
          if (j + k <= K)
          {
            if (DP[to][k] != "絶")
            {
              DP[i][j + k] = min(DP[i][j + k], strings[j] + DP[to][k]);
            }
          }
        }
      }
    }
  }
  string min_string = "絶";
  for (int i = 0; i < scc.nodes.size(); i++)
  {
    min_string = min(min_string, DP[i][K]);
  }
  if (min_string == "絶")
  {
    cout << -1 << endl;
  }
  else
  {
    cout << min_string << endl;
  }
  return 0;
}