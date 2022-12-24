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
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

ll dfs(vector<vector<ll>> &G,ll current,ll parent,ll k,set<ll> &s){
  s.insert(current);
  if (k == 0){
    return 0;
  }
  ll total = current;
  for(auto to:G[current]){
    if (to != parent){
      dfs(G,to,current,k-1,s);
    }
  }
  return 0;
}
int solve()
{
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> G(N);
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll x,k;
    cin >> x >> k;
    x--;
    set<ll> s;
    dfs(G,x,-1,k,s);
    ll ans = 0;
    for(auto v:s){
      ans += v + 1;
    }
    cout << ans << "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
