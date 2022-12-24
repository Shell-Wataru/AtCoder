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

int solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> a(2, vector<ll>(n));
  for (int i = 0; i < n; i++)
  {
    cin >> a[0][i];
    a[0][i]++;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> a[1][i];
    a[1][i]++;
  }
  // cout << "!!" << endl;
  a[0][0] = 0;
  vector<ll> upper_go(n);
  upper_go[n - 1] = a[0][n - 1];
  vector<ll> lower_go(n);
  lower_go[n - 1] = a[1][n - 1];
  vector<ll> upper_back(n);
  upper_back[n - 1] = a[0][n - 1];
  vector<ll> lower_back(n);
  lower_back[n - 1] = a[1][n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    upper_go[i] = max(upper_go[i + 1], a[0][i] + (n - 1) - i);
    lower_go[i] = max(lower_go[i + 1], a[1][i] + (n - 1) - i);
    upper_back[i] = max(upper_back[i + 1] + 1, a[0][i]);
    lower_back[i] = max(lower_back[i + 1] + 1, a[1][i]);
  }
  ll ans = numeric_limits<ll>::max();
  ll t = -1;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      t = max(a[0][i], t + 1);
      ll x = max(upper_go[i], t + n - 1 - i);
      ll y = max(a[1][n - 1], x + 1);
      ans = min(ans, max(lower_back[i], y + n - 1 - i));

      t = max(a[1][i], t + 1);
      x = max(lower_go[i], t + n - 1 - i);
      y = max(a[0][n - 1], x + 1);
      if (i + 1 < n)
      {
        ans = min(ans, max(upper_back[i + 1], y + n - 1 - i));
      }
    }
    else
    {
      t = max(a[1][i], t + 1);
      ll x = max(lower_go[i], t + n - 1 - i);
      ll y = max(a[0][n - 1], x + 1);
      ans = min(ans, max(upper_back[i], y + n - 1 - i));

      t = max(a[0][i], t + 1);
      x = max(upper_go[i], t + n - 1 - i);
      y = max(a[1][n - 1], x + 1);
      if (i + 1 < n)
      {
        ans = min(ans, max(lower_back[i + 1], y + n - 1 - i));
      }
    }
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
