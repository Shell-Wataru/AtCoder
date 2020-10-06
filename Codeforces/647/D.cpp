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
ll BASE_NUM = 998244353;

int solve()
{
  ll n, x;
  cin >> n >> x;
  vector<ll> days(n);
  for(int i = 0;i < n;i++){
    scanf("%lld", &days[i]);
  }
  ll from = 0;
  ll to = 0;
  ll days_sum = 0;
  ll hugs_sum = 0;
  bool started = false;
  ll max_hugs = 0;
  while (!started || from > 0)
  {
    started = true;
    while (days_sum < x)
    {
      days_sum += days[to];
      hugs_sum += days[to] * (days[to] + 1) / 2;
      to = (to + 1) % n;
    }
    ll remove_days = days_sum - x;
    ll last_to = (to + n - 1)% n;
    // cout << from << "~" << to <<":"<< hugs_sum << ","<<remove_days<< endl;

    if (days[from] < days[to])
    {
      if (remove_days <= days[from])
      {
        max_hugs = max(max_hugs, hugs_sum - remove_days * (remove_days + 1) / 2);
      }
      else
      {
        ll remove_tos = remove_days - days[from];
        ll remove_to_hugs = remove_tos * (days[last_to] + (days[last_to] - remove_tos + 1)) / 2;
        max_hugs = max(max_hugs, hugs_sum - days[from] * (days[from] + 1) / 2 - remove_to_hugs);
      }
    }
    else
    {
      if (remove_days <= days[last_to])
      {
        max_hugs = max(max_hugs, hugs_sum - remove_days * (remove_days + 1) / 2);
      }
      else if (remove_days <= days[last_to] * 2)
      {
        ll remove_from_hugs = days[last_to] * (days[last_to] + 1) / 2;
        ll remove_tos = remove_days - days[last_to];
        ll remove_to_hugs = remove_tos * (days[last_to] + (days[last_to] - remove_tos + 1)) / 2;
        max_hugs = max(max_hugs, hugs_sum - remove_from_hugs - remove_to_hugs);
      }
      else
      {
        ll remove_froms = remove_days - days[last_to];
        ll remove_from_hugs = remove_froms * (remove_froms + 1)/2;
        ll remove_to_hugs = days[last_to] * (days[last_to] + 1) / 2;
        max_hugs = max(max_hugs, hugs_sum - remove_from_hugs - remove_to_hugs);
      }
    }
    days_sum -= days[from];
    hugs_sum -= days[from] * (days[from] + 1) / 2;
    from = (from + 1) % n;
  }
  cout << max_hugs << endl;
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  // cout << flush;
  return 0;
}