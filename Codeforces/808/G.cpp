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

  void build() {
    dfs(0, -1, 0);
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


int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> G(n);
  for(int i = 0;i < n-1;i++){
    ll u,v;
    scanf("%lld",&u);
    scanf("%lld",&v);
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DoublingLowestCommonAncestor lca(G);
  lca.build();
  ll q;
  cin >> q;
  for(int i = 0;i < q;i++){
    ll k;
    scanf("%lld",&k);
    vector<pair<ll,ll>> points(k);
    for(int j = 0;j < k;j++){
        scanf("%lld",&points[j].second);
        points[j].second--;
        points[j].first = lca.dep[points[j].second];
    }
    ll root = -1;
    sort(points.rbegin(),points.rend());
    vector<ll> lefts;
    vector<ll> rights;
    lefts.push_back(points[0].second);
    bool is_ok = true;
    // cout << 0 << ":" << points[0].second << endl;
    for(int j = 1;j < k;j++){
        // cout << j << ":" << points[j].second << endl;
        ll r = lca.query(lefts[0],points[j].second);
        // cout << "root:"<< r << endl;
        if (root == -1 && r == points[j].second){
            lefts.push_back(points[j].second);
        }else if (root == -1){
            rights.push_back(points[j].second);
            root = r;
        }else if(root == r){
            rights.push_back(points[j].second);
        }else{
            is_ok = false;
            continue;
        }
    }
    for(int j = 1;j < rights.size();j++){
        ll r = lca.query(rights[j-1],rights[j]);
        if (r != rights[j]){
            is_ok = false;
            continue;
        }
    }
    if (is_ok){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
  }
  return 0;
}
int main()
{
  // ios_base::sync_with_stdio(0); cin.tie(0);
//   int t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
  solve();
//   }
  cout << flush;
  return 0;
}