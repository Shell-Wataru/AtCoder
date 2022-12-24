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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll a, b;
  scanf("%lld", &a);
  scanf("%lld", &b);
  ll base = 0;
  while (b >= 1ll << (base))
  {
    base++;
  }
  ll ans = numeric_limits<ll>::max();
  for (int i = b; i < 1ll << base; i++)
  {
    ll take = i - b;
    ll current_a = a;
    for (ll j = 0; j < 25; j++)
    {
      if ((current_a & 1ll << j) && !(i & 1ll << j))
      {
        current_a += 1ll << j;
        current_a -= current_a % (1ll << j);
      }
    }
    if (current_a != i)
    {
      take++;
    }
    take += current_a - a;
    if (current_a <= i)
    {
      ans = min(ans, take);
    }
  }
  cout << ans << endl;
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