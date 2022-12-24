#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_set>
using namespace std;
using ll = long long;

template< typename G >
struct DoublingLowestCommonAncestor {
  const int LOG;
  vector< int > dep;
  const G &g;
  vector< vector< int > > table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
    table.assign(LOG, vector< int >(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to : g[idx]) {
      if(to != par) dfs(to, idx, d + 1);
    }
  }

  void build(ll root) {
    dfs(root, -1, 0);
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};

int dfs(vector<vector<vector<ll>>> &G, ll current,ll parent,
ll distance,
vector<ll> &idx,
vector<ll> &distances,
vector<vector<ll>> &color_indices,vector<vector<ll>> &color_distances,vector<vector<ll>> &color_edge_counts){
    if(idx[current] == -1){
        idx[current] = distances.size();
    }
    // cout << current << endl;
    distances.push_back(distance);
    for(auto e:G[current]){
        ll to = e[0];
        ll color = e[1];
        ll d = e[2];
        if (to != parent){
            color_indices[color].push_back(distances.size());
            color_distances[color].push_back(color_distances[color].back()+d);
            color_edge_counts[color].push_back(color_edge_counts[color].back()+1);
            dfs(G,to,current,distance+d,idx,distances,color_indices,color_distances,color_edge_counts);
            color_indices[color].push_back(distances.size());
            color_distances[color].push_back(color_distances[color].back()-d);
            color_edge_counts[color].push_back(color_edge_counts[color].back()-1);
        }
    }
    return 0;
}
int solve()
{
    ll N,Q;
    cin >> N >> Q;
    vector<vector<vector<ll>>> G(N);
    vector<vector<ll>> baseG(N);
    for(int i = 0;i < N-1;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        G[a].push_back({b,c,d});
        G[b].push_back({a,c,d});
        baseG[a].push_back(b);
        baseG[b].push_back(a);
    }
    DoublingLowestCommonAncestor<vector<vector<ll>>> lca(baseG);
    lca.build(0);
    // cout <<"!!" << endl;
    vector<vector<ll>> color_edge_counts(N,{0});
    vector<vector<ll>> color_distances(N,{0});
    vector<vector<ll>> color_indices(N,{0});
    vector<ll> idx(N,-1);
    vector<ll> distances(N);
    dfs(G,0,-1,0,idx,distances,color_indices,color_distances,color_edge_counts);
    // cout << "!" << endl;
    for(int i = 0;i < Q;i++){
        ll x,y,u,v;
        cin >> x >> y >> u >> v;
        u--;v--;
        ll ancestor = lca.query(u,v);
        ll d = distances[idx[u]] - distances[idx[ancestor]] + distances[idx[v]] - distances[idx[ancestor]];
        auto iter_u = upper_bound(color_indices[x].begin(),color_indices[x].end(),idx[u]);
        auto iter_v = upper_bound(color_indices[x].begin(),color_indices[x].end(),idx[v]);
        auto iter_ancestor = upper_bound(color_indices[x].begin(),color_indices[x].end(),idx[ancestor]);
        iter_u--;
        iter_v--;
        iter_ancestor--;
        ll index_u = iter_u - color_indices[x].begin();
        ll index_v = iter_v- color_indices[x].begin();
        ll index_ancestor = iter_ancestor- color_indices[x].begin();
        // cout << index_u << "," << index_v << "," << index_ancestor << endl;
        // cout << d << endl;
        d -=  color_distances[x][index_u] - color_distances[x][index_ancestor] + color_distances[x][index_v] - color_distances[x][index_ancestor];
        d +=  (color_edge_counts[x][index_u] - color_edge_counts[x][index_ancestor] + color_edge_counts[x][index_v] - color_edge_counts[x][index_ancestor]) * y;
        cout << d << "\n";
    }
    cout << flush;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
