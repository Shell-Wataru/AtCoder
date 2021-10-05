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
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

ll p2(ll l, ll r)
{
  if (l + 1 == r)
  {
    return r;
  }
  ll center = (l + r) / 2;
  cout << "? 1 1 2 " << center << endl;
  ll y;
  scanf("%lld", &y);
  if (y == center + 1)
  {
    return p2(center, r);
  }
  else
  {
    return p2(l, center);
  }
}

int solve()
{
  int n;
  scanf("%d", &n);
  vector<ll> p(n, -1);
  p[1] = p2(0, n);
  if (p[1] <= n / 2)
  {
    for (int i = 0; i < n; i++)
    {
      if (i == 1)
      {
        continue;
      }
      cout << "? 1 2 " << i + 1 << " " << n - 1 << endl;
      ll y;
      scanf("%lld", &y);
      if (y > p[1])
      {
        p[i] = y;
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (i == 1 || p[i] != -1)
      {
        continue;
      }
      cout << "? 2 " << i + 1 << " 2 1" << endl;
      ll y;
      scanf("%lld", &y);
      if (y < p[1])
      {
        p[i] = y;
      }
    }
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      if (i == 1)
      {
        continue;
      }
      cout << "? 2 " << i + 1 << " 2 1" << endl;
      ll y;
      scanf("%lld", &y);
      if (y < p[1])
      {
        p[i] = y;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (i == 1 || p[i] != -1)
      {
        continue;
      }
      cout << "? 1 2 " << i + 1 << " " << n - 1 << endl;
      ll y;
      scanf("%lld", &y);
      if (y > p[1])
      {
        p[i] = y;
      }
    }
  }
  cout << "!";
  for (size_t i = 0; i < n; i++)
  {
    cout << " " << p[i];
  }
  cout << endl;
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
