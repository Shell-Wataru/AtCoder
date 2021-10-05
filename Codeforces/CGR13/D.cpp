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
int BASE_NUM = 998244353;

bool can_reach(ll u, ll v)
{
  if (v < u)
  {
    return false;
  }
  ll u_one_counts = 0;
  ll v_one_counts = 0;

  for (int i = 0; i < 31; i++)
  {
    if (u & 1 << i)
    {
      u_one_counts++;
    }
    if (v & 1 << i)
    {
      v_one_counts++;
    }
    if (v_one_counts > u_one_counts)
    {
      return false;
    }
  }
  return u_one_counts >= v_one_counts;
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  for (int i = 0; i < n; i++)
  {
    ll u, v;
    scanf("%lld", &u);
    scanf("%lld", &v);
    if (can_reach(u, v))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}