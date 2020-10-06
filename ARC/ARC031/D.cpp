#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

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

double min_cut(vector<ll> &S, vector<ll> &T, vector<vector<ll>> &A, double t)
{
  ll N = S.size();
  ll M = T.size();
  double total_exp = 0;
  Dinic<double> dinic(N + M + 2);
  for (int i = 0; i < N; i++)
  {
    total_exp += S[i];
    dinic.add_edge(0, i + 1, S[i]);
  }
  for (int i = 0; i < M; i++)
  {
    // total += t * T[i];
    dinic.add_edge(N + i + 1, N + M + 1, t * T[i]);
  }
  for (int i = 0; i < N; i++)
  {
    for (auto to : A[i])
    {
      dinic.add_edge(i + 1, N + to, 1e9);
    }
  }
  double flow = dinic.max_flow(0, N + M + 1);
  // cout << t << ":" << flow << endl;
  return total_exp - flow;
}

double solve(double l, double r, vector<ll> &S, vector<ll> &T, vector<vector<ll>> &A)
{
  if (r - l < 1e-6)
  {
    return r;
  }
  double center = (l + r) / 2;
  if (min_cut(S, T, A, center) <= 0)
  {
    return solve(l, center, S, T, A);
  }
  else
  {
    return solve(center, r, S, T, A);
  }
}

int main()
{
  // 整数の入力
  ll N, M;
  scanf("%lld", &N);
  scanf("%lld", &M);
  vector<ll> S(N);
  vector<ll> T(M);
  vector<vector<ll>> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &S[i]);
  }
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &T[i]);
  }

  for (int i = 0; i < N; i++)
  {
    ll K;
    scanf("%lld", &K);
    A[i] = vector<ll>(K);
    for (int j = 0; j < K; j++)
    {
      scanf("%lld", &A[i][j]);
    }
  }
  // cout << min_cut(S, T, A, 0) << endl;
  // cout << min_cut(S, T, A, 1) << endl;
  // cout << min_cut(S, T, A, 2) << endl;
  cout << fixed << setprecision(12) << solve(0, 1e9, S, T, A) << endl;
  return 0;
}