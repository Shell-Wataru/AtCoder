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

int solve()
{

    ll N, M, a , b;
    cin >> N >> M >> a >> b;
    Dinic<ll> dinic(N+M+2);
    for(int i  = 1;i <= N;i++){
        dinic.add_edge(0,i,a);
    }
    for(int i  = 1;i <= M;i++){
        dinic.add_edge(N + i, N + M + 1,b);
    }
    for(int i = 1; i <= N;i++){
        for(int j = 1;j <= M;j++){
            dinic.add_edge(i,N+j,1);
        }
    }
    ll max_flow = dinic.max_flow(0,N+M+1);
    if (max_flow == N * a && N * a == M * b){
        cout << "YES" << endl;
        for(int i = 1; i <= N;i++){
            vector<char> row(M);
            // cout << dinic.graph[i].size() << endl;
            for(auto e:dinic.graph[i]){
                if (!e.isrev){
                    ll j = e.to - N - 1;
                    // cout << "j"<<j << endl;
                    if(e.cap == 0){
                        row[j] = '1';
                    }else{
                        row[j] = '0';
                    }
                }
            }
            for(auto c:row){
                cout << c;
            }
            cout << endl;
        }
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
    return 0;
}