#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
int BASE_NUM = 998244353;

template <typename flow_t>
struct Dinic
{
  const flow_t INF;

  struct edge
  {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector<vector<edge>> graph;
  vector<int> min_cost, iter;

  Dinic(int V) : INF(numeric_limits<flow_t>::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1)
  {
    graph[from].emplace_back((edge){to, cap, (int)graph[to].size(), false, idx});
    graph[to].emplace_back((edge){from, 0, (int)graph[from].size() - 1, true, idx});
  }

  bool bfs(int s, int t)
  {
    min_cost.assign(graph.size(), -1);
    queue<int> que;
    min_cost[s] = 0;
    que.push(s);
    while (!que.empty() && min_cost[t] == -1)
    {
      int p = que.front();
      que.pop();
      for (auto &e : graph[p])
      {
        if (e.cap > 0 && min_cost[e.to] == -1)
        {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(int idx, const int t, flow_t flow)
  {
    if (idx == t)
      return flow;
    for (int &i = iter[idx]; i < graph[idx].size(); i++)
    {
      edge &e = graph[idx][i];
      if (e.cap > 0 && min_cost[idx] < min_cost[e.to])
      {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if (d > 0)
        {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t)
  {
    flow_t flow = 0;
    while (bfs(s, t))
    {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while ((f = dfs(s, t, INF)) > 0)
        flow += f;
    }
    return flow;
  }

  void output()
  {
    for (int i = 0; i < graph.size(); i++)
    {
      for (auto &e : graph[i])
      {
        if (e.isrev)
          continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> A(2 * n);
  for (ll i = 0; i < 2 * n; i++)
  {
    scanf("%lld", &A[i]);
  }
  Dinic<ll> dinic(2 * n + 2);
  ll before_max = -1;
  for (int i = 0; i < 2 * n; i++)
  {
    if (A[i] > before_max)
    {
      dinic.add_edge(0, i + 1, n);
      cout << "head" << A[i] << endl;
    }
    dinic.add_edge(i + 1, 2 * n + 1, 1);
    before_max = max(before_max, A[i]);
    for (size_t j = i + 1; j < 2* n; j++)
    {
      if (A[j] < A[i])
      {
        cout << A[i] << "->" << A[j] << endl;
        dinic.add_edge(i + 1, j + 1, n);
      }
    }
  }
  if (dinic.max_flow(0, 2 * n + 1) == 2 * n){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  // cout << flush;
  return 0;
}