#define _USE_MATH_DEFINES
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

int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  ll ans = 0;
  for(int i = 1;i <= n;i++){
    vector<vector<ll>> DP(i+1,vector<ll>(i));
    DP[0][0] = 1;
    for(int j = 0;j < n;j++){
        for(int k = i-1;k >= 0;k--){
            for(int l = 0;l < i;l++){
                DP[k+1][(l+a[j])%i] += DP[k][l];
                DP[k+1][(l+a[j])%i] %= 998244353;
            }
        }
    }
    ans += DP[i][0];
    ans %= 998244353;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
