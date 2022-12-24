#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

ll query(ll l, ll r)
{
  cout << "? " << (l + 1) << " " << r << endl;
  ll ans;
  cin >> ans;
  return ans;
}

ll find_r(ll l, ll r, ll total)
{
  if (l + 1 == r)
  {
    return r;
  }
  ll center = (l + r) / 2;
  ll current = query(0, center);
  if (current == total)
  {
    return find_r(l, center, total);
  }
  else
  {
    return find_r(center, r, total);
  }
}

ll find_l_length(ll l, ll r, ll total)
{
  if (l + 1 == r)
  {
    return r;
  }
  ll center = (l + r) / 2;
  if (center * (center - 1) / 2 >= total)
  {
    return find_l_length(l, center, total);
  }
  else
  {
    return find_l_length(center, r, total);
  }
}

int solve()
{
  ll n;
  cin >> n;
  ll total = query(0, n);
  ll r = find_r(0, n, total);
  ll r_length = total - query(0, r - 1) + 1;
  ll l_total = total - r_length * (r_length - 1) / 2;
  ll l_length = find_l_length(0, n, l_total);
  cout << "! " << r - r_length - l_length + 1 << " " << r - r_length + 1 << " " << r << endl;
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
  return 0;
}