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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n, k, l;
  cin >> n >> k >> l;
  vector<ll> depths(n + 1, 0);
  for (size_t i = 1; i <= n; i++)
  {
    scanf("%lld", &depths[i]);
  }

  ll from = 0;
  ll to = 2 * k - 1;
  bool can = true;
  for (int i = 1; i <= n; i++)
  {
    ll diff = l - depths[i];
    ll base_from = max(k - diff, 0ll);
    ll base_to = min(k + diff, 2 * k - 1);
    // cout << base_from << "~" << base_to << endl;
    if (base_from == 0 && base_to == 2 * k - 1)
    {
      from = 0;
      to = 2 * k - 1;
    }
    else if (base_to < base_from)
    {
      can = false;
      break;
    }
    else if (from == 0 && to == 2 * k - 1)
    {
      from = base_from;
      to = base_to;
    }
    else
    {
      if (to + 1 < base_from || base_to < from + 1)
      {
        can = false;
        break;
      }
      else
      {
        from = max(from + 1, base_from);
        to = base_to;
        if (to < from){
          can = false;
          break;
        }
      }
    }
  }
  if (can)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
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
