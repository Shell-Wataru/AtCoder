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

int main()
{
    // 整数の入力
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    ll n = s1.size()/2;
    vector<ll> s1_count(26,0);
    vector<ll> s2_count(26,0);
    vector<ll> s3_count(26,0);
    for(auto c:s1){
        s1_count[c - 'A']++;
    }
    for(auto c:s2){
        s2_count[c - 'A']++;
    }
    for(auto c:s3){
        s3_count[c - 'A']++;
    }
    Dinic<ll> dinic(26+4);
    dinic.add_edge(0,1,n);
    dinic.add_edge(0,2,n);
    for(int i = 0;i < 26;i++){
        // cout << s1_count[i] << ",";
        dinic.add_edge(1,3+i,s1_count[i]);
    }
    // cout << endl;
    for(int i = 0;i < 26;i++){
        // cout << s2_count[i] << ",";
        dinic.add_edge(2,3+i,s2_count[i]);
    }
    // cout << endl;
    for(int i = 0;i < 26;i++){
        // cout << s3_count[i] << ",";
        dinic.add_edge(3+i,26+3,s3_count[i]);
    }
    // cout << endl;
    if (dinic.max_flow(0,26+3) == 2 * n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}