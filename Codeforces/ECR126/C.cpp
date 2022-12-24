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

ll days(ll odd, ll even)
{
  if (odd > even)
  {
    return 2 * odd - 1;
  }
  else
  {
    ll d = even - odd;
    if (d % 3 == 0)
    {
      return 2 * odd + 4 * (d / 3);
    }
    else if (d % 3 == 1)
    {
      // return "!" ;
      return 2 * odd + 4 * (d / 3) + 2;
    }
    else
    {
      return 2 * odd + 4 * (d / 3) + 3;
    }
  }
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll odd1 = 0;
  ll even1 = 0;
  ll odd2 = 0;
  ll even2 = 0;
  for (int i = 0; i < n; i++)
  {
    if ((a[n - 1] - a[i]) % 2 == 1)
    {
      odd1++;
    }
    even1 += (a[n - 1] - a[i]) / 2;
  }
  for (int i = 0; i < n; i++)
  {
    if ((a[n - 1] + 1- a[i]) % 2 == 1)
    {
      odd2++;
    }
    even2 += (a[n - 1] + 1 - a[i]) / 2;
  }
  ll ans = numeric_limits<ll>::max();
  ans = min(ans,days(odd1,even1));
  ans = min(ans,days(odd2,even2));
  cout << ans << "\n";
  return 0;
}
int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
