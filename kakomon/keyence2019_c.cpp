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
  deque<ll> A(n);
  deque<ll> B(n);
  for(int i = 0;i < n;i++){
    cin >> A[i];
  }
  for(int i = 0;i < n;i++){
    cin >> B[i];
  }
  for(int i = 0;i < n;i++){
    A[i] = A[i]-B[i];
  }
  sort(A.rbegin(),A.rend());
  ll count = 0;
  bool front_changed = false;
  bool back_changed = false;
  ll ans = 0;
  while(true){
    if (A.front() == 0){
        A.pop_front();
        front_changed = false;
    }else if (A.back() == 0){
        A.pop_back();
        back_changed = false;
    }else if(A.front() > 0 && A.back() > 0){
        break;
    }else if(A.front() > 0 && A.back() < 0){
        ll d = min(A.front(),-A.back());
        A.front() -= d;
        A.back() += d;
        if (!front_changed){
            ans++;
            front_changed= true;
        }
        if (!back_changed){
            ans++;
            back_changed= true;
        }
    }else{
        cout << -1 << endl;
        return 0;
    }
  }
  cout << ans << endl;
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