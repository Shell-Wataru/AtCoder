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
  ll n, mod;
  scanf("%lld", &n);
  scanf("%lld", &mod);
  vector<vector<ll>> DP(n + 1, vector<ll>(n * (n-1)/2 + 1));
  DP[1][0] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < n * (n - 1) / 2; j++)
    {
      for (int k = 0; k <= i; k++)
      {
        // cout << i << "," << j + k << endl;
        DP[i + 1][j + k] = (DP[i + 1][j + k] + DP[i][j]) % mod;
      }
    }
  }
  // cout << "!!" << endl;
  // for(int i = 1;i <= n;i++){
  //   for(int j = 0;j < n*n;j++){
  //     cout << DP[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  vector<vector<ll>> ruisekiWa(n + 1, vector<ll>(n * (n-1)/2 + 1));
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < n * (n - 1) / 2; j++)
    {
      ruisekiWa[i][j + 1] = (ruisekiWa[i][j] + DP[i][j]) % mod;
    }
  }
  ll ans = 0;
  ll times = 1;
  for (int i = n; i >= 1; i--)
  {
    // cout << i << endl;
    ll patterns = 0;
    for (int diff = 1; diff <= i - 1; diff++)
    {
      ll diff_patterns = 0;
      for (int l = 0; l + diff + 1 <= n * (n - 1) / 2; l++)
      {
        // cout <<ruisekiWa[i-1][l+1] << "," << DP[i-1][l+diff+1] <<` endl;
        diff_patterns = (diff_patterns + ruisekiWa[i - 1][l + 1] * DP[i - 1][l + diff + 1]) % mod;
      }
      patterns = patterns + diff_patterns * (i - diff);
      patterns %= mod;
    }
    ans = (ans + patterns* times) % mod;
    times = times * i ;
    times %= mod;
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
