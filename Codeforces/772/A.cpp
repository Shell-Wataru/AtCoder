#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  vector<bool> found(30);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      if (a[i] & 1ll << j)
      {
        found[j] = true;
      }
    }
  }
  ll ans = 0;
  for (int j = 0; j < 30; j++)
  {
    if (found[j])
    {
      ans += 1ll << j;
    }
  }
  cout << ans;
  cout << "\n";
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