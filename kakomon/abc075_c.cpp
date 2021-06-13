// https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

template< typename G >
struct LowLink {
  const G &g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;

  LowLink(const G &g) : g(g) {}

  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }

  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }
};

int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for(int i = 0; i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LowLink<vector<vector<ll>>> lowlink(G);
    lowlink.build();
    cout << lowlink.bridge.size() << endl;
    return 0;
}