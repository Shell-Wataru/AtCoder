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

template <typename T>
struct Compress
{
  vector<T> xs;

  Compress() = default;

  Compress(const vector<T> &vs)
  {
    add(vs);
  }

  Compress(const initializer_list<vector<T>> &vs)
  {
    for (auto &p : vs)
      add(p);
  }

  void add(const vector<T> &vs)
  {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x)
  {
    xs.emplace_back(x);
  }

  void build()
  {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector<int> get(const vector<T> &vs) const
  {
    vector<int> ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
              { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
    return ret;
  }

  int get(const T &x) const
  {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  size_t size() const
  {
    return xs.size();
  }
  const T &operator[](int k) const
  {
    return xs[k];
  }
};

template <typename flow_t, typename cost_t>
struct PrimalDual
{
  const cost_t INF;

  struct edge
  {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector<vector<edge>> graph;
  vector<cost_t> potential, min_cost;
  vector<int> prevv, preve;

  PrimalDual(int V) : graph(V), INF(numeric_limits<cost_t>::max()) {}

  void add_edge(int from, int to, flow_t cap, cost_t cost)
  {
    graph[from].emplace_back((edge){to, cap, cost, (int)graph[to].size(), false});
    graph[to].emplace_back((edge){from, 0, -cost, (int)graph[from].size() - 1, true});
  }

  cost_t min_cost_flow(int s, int t, flow_t f)
  {
    int V = (int)graph.size();
    cost_t ret = 0;
    using Pi = pair<cost_t, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while (f > 0)
    {
      min_cost.assign(V, INF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while (!que.empty())
      {
        Pi p = que.top();
        que.pop();
        if (min_cost[p.second] < p.first)
          continue;
        for (int i = 0; i < graph[p.second].size(); i++)
        {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if (e.cap > 0 && min_cost[e.to] > nextCost)
          {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if (min_cost[t] == INF)
        return -1;
      for (int v = 0; v < V; v++)
        potential[v] += min_cost[v];
      flow_t addflow = f;
      for (int v = t; v != s; v = prevv[v])
      {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for (int v = t; v != s; v = prevv[v])
      {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
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
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};

ll solve()
{
  ll N;
  scanf("%lld",&N);
  Compress<ll> colleges;
  Compress<ll> skills;
  ll maximum_skill = 0;
  map<pair<ll,ll>,ll> maximum_skills;
  for (int i = 0; i < N; i++)
  {
    ll A, B, C;
    scanf("%lld",&A);
    scanf("%lld",&B);
    scanf("%lld",&C);
    colleges.add(A);
    skills.add(B);
    maximum_skill = max(maximum_skill, C);
    maximum_skills[{A,B}] = max(maximum_skills[{A,B}],C);
  }
  colleges.build();
  skills.build();
  vector<ll> answers;
  PrimalDual<int, int> g(2 + colleges.size() + skills.size());
  for (int i = 0; i < colleges.size(); i++)
  {
    g.add_edge(0, i + 1, 1, 0);
  }
  for (int i = 0; i < skills.size(); i++)
  {
    g.add_edge(colleges.size() + i + 1, colleges.size() + skills.size() + 1, 1, 0);
  }
  for(auto &p:maximum_skills){
    g.add_edge(colleges.get(p.first.first) + 1, colleges.size() + skills.get(p.first.second) + 1, 1, maximum_skill + 1 - p.second);
  }

  ll ans = 0;
  for (int j = 1; j <= min(colleges.size(),skills.size()); j++)
  {
    ll min_flow = g.min_cost_flow(0, colleges.size() + skills.size() + 1, 1);
    ans += maximum_skill + 1 - min_flow;
    if (min_flow != -1)
    {
      answers.push_back(ans);
    }else{
      break;
    }
  }
  cout << answers.size() << "\n";
  for (auto a : answers)
  {
    cout << a << "\n";
  }
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
