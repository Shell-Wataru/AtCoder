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

ll BASE_NUM = 1000000007;

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

int set_edges(ll N, ll M, vector<string> &G, ll u, ll v, PrimalDual<ll,ll> &dinic)
{
    queue<pair<ll, ll>> q;
    q.push({u, v});
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<pair<ll, ll>> directions = {{1, 0}, {0, 1}};
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        ll d = p.first - u + p.second - v;
        dinic.add_edge(M * u + v + 1, M * N + M * x + y + 1,1,N+M-d);
        for (auto d : directions)
        {
            ll next_x = x + d.first;
            ll next_y = y + d.second;
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M && !visited[next_x][next_y] && G[next_x][next_y] != '#')
            {
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
            }
        }
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<string> G(N);
    PrimalDual<ll,ll> dinic(2 * N * M + 2);
    for (size_t i = 0; i < N; i++)
    {
        cin >> G[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dinic.add_edge(0,M*i + j + 1,1,0);
            dinic.add_edge(N*M + M*i + j + 1, 2*N*M+1,1,0);
        }
    }
    ll pones = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (G[i][j] == 'o'){
                pones++;
                set_edges(N, M, G, i, j, dinic);
            }
        }
    }
    cout << (N+M)*pones - dinic.min_cost_flow(0,2*N*M+1,pones) << endl;
    return 0;
}