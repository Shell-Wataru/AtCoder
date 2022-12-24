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
using namespace std;
using ll = long long;

int solve()
{
  int n,m;
  scanf("%d", &n);
  scanf("%d", &m);
  vector<vector<ll>> G(n);
  for (int i = 0; i < m; i++)
  {
    ll u, v;
    scanf("%lld", &u);
    scanf("%lld", &v);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<vector<ll>> DP(n,vector<ll>(1ll<<n,0));
  DP[0][1] = 1;
  for(int i = 1;i < 1ll<<n;i++){
      for(int j = 0;j < n;j++){
          if (i & 1ll<<j){
              for(auto to:G[j]){
                  if (!(i & 1ll<<to)){
                      DP[to][i | 1ll<<to] += DP[j][i];
                  }
              }
          }
      }
  }
  ll ans = 0;
  for(int i = 0;i < n;i++){
      ans += DP[i][(1ll<<n)-1];
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
