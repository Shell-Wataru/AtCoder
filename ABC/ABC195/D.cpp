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

using namespace std;
using ll = long long;

template< typename flow_t, typename cost_t >
struct PrimalDual {
  const cost_t INF;

  struct edge {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector< vector< edge > > graph;
  vector< cost_t > potential, min_cost;
  vector< int > prevv, preve;

  PrimalDual(int V) : graph(V), INF(numeric_limits< cost_t >::max()) {}

  void add_edge(int from, int to, flow_t cap, cost_t cost) {
    graph[from].emplace_back((edge) {to, cap, cost, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, -cost, (int) graph[from].size() - 1, true});
  }

  cost_t min_cost_flow(int s, int t, flow_t f) {
    int V = (int) graph.size();
    cost_t ret = 0;
    using Pi = pair< cost_t, int >;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while(f > 0) {
      min_cost.assign(V, INF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if(min_cost[t] == INF) return -1;
      for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      flow_t addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};

int solve(vector<pair<ll,ll>> &WV, vector<ll> &X){
  ll N = WV.size();
  ll M = X.size();
  ll L,R;
  scanf("%lld",&L);
  scanf("%lld",&R);
  L--;
  R--;
  PrimalDual< int, int > g(2 + N + M);
  ll max_value = 0;
  for(int i = 0 ;i < N;i++){
    max_value = max(max_value,WV[i].second);
  }
  for(int i = 0;i < N;i++){
    g.add_edge(0,i+1,1,0);
    g.add_edge(i+1,N + M + 1,1,max_value);
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j < M;j++){
      if (!(L <= j && j <= R) && WV[i].first <= X[j]){
        g.add_edge(i+1,N + j + 1,1,max_value - WV[i].second);
      }
    }
  }
  for(int i = 0;i < M;i++){
    g.add_edge(N+i+1,N + M + 1,1,0);
  }
  // cout << max_value << endl;
  cout << N * max_value - g.min_cost_flow(0,N+M+1,N) << endl;
  return 0;
}

int main()
{
  // 整数の入力
  ll N,M,Q;
  cin >> N >> M >> Q;
  vector<pair<ll,ll>> WV(N);
  vector<ll> X(M);
  PrimalDual< int, int > g(2 + N + M);
  for(int i = 0; i< N;i++){
    scanf("%lld",&WV[i].first);
    scanf("%lld",&WV[i].second);
  }

  for(int i = 0; i< M;i++){
    scanf("%lld",&X[i]);
  }

  for(int i = 0;i < Q;i++){
    solve(WV,X);
  }
  return 0;
}
