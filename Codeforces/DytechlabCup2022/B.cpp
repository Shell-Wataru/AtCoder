#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int floor_root(ll x)
{
  ll a = sqrt(x) - 1;
  ll b = sqrt(x);
  ll c = sqrt(x) + 1;
  if (a * a <= x && x < b * b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
int solve()
{
  ll l, r;
  scanf("%lld", &l);
  scanf("%lld", &r);
  ll l_floor = floor_root(l);
  ll r_floor = floor_root(r);
  // cout << "l:" << l_floor << endl;
  // cout  << "r:"<< r_floor << endl;
  ll ans = max(r_floor - l_floor - 1, 0ll) * 3;
  // cout << ans << endl;
  if (l <= l_floor * l_floor && l_floor * l_floor  <= r)
  {
    // cout << "!" << endl;
    ans++;
  }
  if (l <= l_floor * l_floor + l_floor && l_floor * l_floor + l_floor <= r)
  {
    // cout << "!" << endl;

    ans++;
  }
  if (l <= l_floor * l_floor + l_floor + l_floor && l_floor * l_floor + l_floor + l_floor <= r)
  {
    // cout << "!" << endl;
    ans++;
  }
  if (r_floor != l_floor)
  {
    if (l <= r_floor * r_floor && r_floor * r_floor  <= r)
  {
    // cout << "!" << endl;
    ans++;
  }
  if (l <= r_floor * r_floor + r_floor && r_floor * r_floor + r_floor <= r)
  {
    // cout << "!" << endl;

    ans++;
  }
  if (l <= r_floor * r_floor + r_floor + r_floor && r_floor * r_floor + r_floor + r_floor <= r)
  {
    // cout << "!" << endl;
    ans++;
  }
  }
  cout << ans  << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}