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
const long long BASE_NUM = 1000000007;


int solve()
{
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  vector<set<ll>> panel_lengths(n + 1);
  vector<ll> ans(n);
  vector<ll> k_count(n + 1, 0);
  vector<ll> d_count(n + 1, 0);
  map<pair<ll,ll>,ll> dp;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'K')
    {
      k_count[i + 1] = k_count[i] + 1;
      d_count[i + 1] = d_count[i];
    }
    else
    {
      k_count[i + 1] = k_count[i];
      d_count[i + 1] = d_count[i] + 1;
    }
    ll common = gcd(k_count[i + 1],d_count[i + 1]);
    ans[i] = dp[{k_count[i + 1]/common,d_count[i + 1]/common}] + 1;
    dp[{k_count[i + 1]/common,d_count[i + 1]/common}] += 1;
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   for(auto l:panel_lengths[i]){
  //     cout << l << ",";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n; i++)
  {
    if (i != 0)
    {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
