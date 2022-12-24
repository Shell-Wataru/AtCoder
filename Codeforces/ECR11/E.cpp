#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

const long long BASE_NUM = 998244353;

template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

vector<ll> line1_from_point(vector<ll> p){
    p[0] += p[1];
    ll bumbo = p[1] * p[2];
    ll bunshi = p[0] * p[3];
    return {bunshi/gcd(bunshi,bumbo),bumbo/gcd(bunshi,bumbo)};
}

vector<ll> line2_from_point(vector<ll> p){
    p[2] += p[3];
    ll bumbo = p[1] * p[2];
    ll bunshi = p[0] * p[3];
    return {bunshi/gcd(bunshi,bumbo),bumbo/gcd(bunshi,bumbo)};
}

int solve()
{

    ll n;
    cin >> n;
    vector<vector<ll>> points(n,vector<ll>(4));
    set<vector<ll>> lines;
    map<vector<ll>,vector<ll>> line_points;
    for(int i = 0;i < n;i++){
        scanf("%lld",&points[i][0]);
        scanf("%lld",&points[i][1]);
        scanf("%lld",&points[i][2]);
        scanf("%lld",&points[i][3]);
        lines.insert(line1_from_point(points[i]));
        lines.insert(line2_from_point(points[i]));
        line_points[line1_from_point(points[i])].push_back(i);
        line_points[line2_from_point(points[i])].push_back(i);
    }
    vector<vector<ll>> lines_vector(lines.begin(),lines.end());
    for(auto p:line_points){
        cout << p.second.size() << endl;
    }
    ll l = lines_vector.size();
    // Dinic<ll> dinic(l+n+2);
    // for(int i = 0;i < l;i++){
    //     dinic.add_edge(0,i+1,n);
    // }
    // for(int i = 0;i < l;i++){
    //     for(auto to:line_points[lines_vector[i]]){
    //         dinic.add_edge(i+1,l+to+1,1);
    //     }
    // }
    // for(int i = 0;i < n;i++){
    //     dinic.add_edge(l+i+1, l+n+1,1);
    // }
    // cout << dinic.max_flow(0,l+n+1) << endl;
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}