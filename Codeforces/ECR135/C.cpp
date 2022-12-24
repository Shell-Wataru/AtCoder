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

ll length(ll a)
{
  ll ans = 0;
  while (a > 0)
  {
    ans++;
    a /= 10;
  }
  return ans;
}
int solve()
{
  ll n;
  cin >> n;
  map<ll, ll> counts;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    counts[a]++;
  }
  for (int i = 0; i < n; i++)
  {
    ll b;
    cin >> b;
    counts[b]--;
    if (counts[b] == 0)
    {
      counts.erase(b);
    }
  }
  ll ans = 0;
  while (!counts.empty())
  {
    auto p = *counts.rbegin();
    // cout << p.first << endl;
    ll l = length(p.first);
    counts[l] += p.second;
    ans+= abs(p.second);
    if (counts[l] == 0)
    {
      counts.erase(l);
    }
    counts.erase(p.first);
  }
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
