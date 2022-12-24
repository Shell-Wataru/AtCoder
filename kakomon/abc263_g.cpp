#define _USE_MATH_DEFINES
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

vector<ll> prime_numbers(int n)
{
  if (n <= 1)
  {
    return vector<ll>(0);
  }
  vector<ll> ans = {2};
  for (int i = 3; i <= n; i++)
  {
    bool is_prime = true;
    for (int j = 0; ans[j] * ans[j] <= i; j++)
    {
      if (i % ans[j] == 0)
      {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
    {
      ans.push_back(i);
    }
  }
  return ans;
}
vector<ll> primes = prime_numbers(100000);

bool is_prime(ll p)
{
  for (int i = 0; primes[i] * primes[i] <= p; i++)
  {
    if (p % primes[i] == 0)
    {
      return false;
    }
  }
  return true;
}

ll value(vector<pair<ll, ll>> &odds, vector<pair<ll, ll>> &evens, ll ones, ll use_ones)
{
  Dinic<ll> dinic(odds.size() + evens.size() + 2 + 1);
  dinic.add_edge(0, 1, use_ones);
  for (int i = 0; i < odds.size(); i++)
  {
    dinic.add_edge(0, i + 2, odds[i].second);
  }
  for (int i = 0; i < evens.size(); i++)
  {
    dinic.add_edge(odds.size() + i + 2, odds.size() + evens.size() + 2, evens[i].second);
  }
  for (int j = 0; j < evens.size(); j++)
  {
    if (is_prime(1 + evens[j].first))
    {
      dinic.add_edge(1, odds.size() + j + 2, numeric_limits<ll>::max() / 2);
    }
  }
  for (int i = 0; i < odds.size(); i++)
  {
    for (int j = 0; j < evens.size(); j++)
    {
      if (is_prime(odds[i].first + evens[j].first))
      {
        dinic.add_edge(i + 2, odds.size() + j + 2, numeric_limits<ll>::max() / 2);
      }
    }
  }

  return dinic.max_flow(0, odds.size() + evens.size() + 2) + (ones - use_ones) / 2;
}

ll binary_search(vector<pair<ll, ll>> &odds, vector<pair<ll, ll>> &evens, ll ones, ll l, ll r)
{
  // cout << l << "~" << r << endl;
  if (l+1 == r){
    return l;
  }else if (l+2 == r){
    ll v1 = value(odds, evens, ones, l);
    ll v2 = value(odds, evens, ones, l+1);
    if (v1 > v2){
      return l;
    }else{
      return l+1;
    }
  }else{
    ll center = (l+r)/2;
    ll v1 = value(odds, evens, ones, center-1);
    ll v2 = value(odds, evens, ones, center+1);
    if (v1 > v2){
      return binary_search(odds, evens, ones, l, center);
    }else{
      return binary_search(odds, evens, ones, center,r);
    }
  }
}

int solve()
{
  ll n;
  cin >> n;
  vector<pair<ll, ll>> odds;
  vector<pair<ll, ll>> evens;
  ll ones = 0;
  for (int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    if (a == 1)
    {
      ones += b;
    }
    else if (a % 2 == 0)
    {
      evens.push_back({a, b});
    }
    else
    {
      odds.push_back({a, b});
    }
  }
  ll used_ones = binary_search(odds, evens, ones, 0, ones + 1);
  // for(int i = 0;i <= ones;i++){
  //   cout << i << ":" << value(odds,evens,ones,i) << endl;
  // }
  cout << value(odds, evens, ones, used_ones) << endl;
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
