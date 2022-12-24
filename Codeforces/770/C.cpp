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
  ll n, k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  if (k == 1)
  {
    cout << "YES\n";
    for (int i = 1; i <= k * n; i++)
    {
      cout << i << "\n";
    }
  }
  else if (k == 2)
  {
    if (n % 2 == 0)
    {
      cout << "Yes\n";
      for (int i = 0; i < n / 2; i++)
      {
        cout << 4 * i + 1 << " " << 4 * i + 3 << "\n";
        cout << 4 * i + 2 << " " << 4 * i + 4 << "\n";
      }
    }
    else
    {
      cout << "No\n";
    }
  }
  else if (n % 2 == 0)
  {
    cout << "Yes\n";
    for (int i = 0; i < n / 2; i++)
    {
      for (int j = 0; j < k; j++)
      {
        if (j != 0)
        {
          cout << " ";
        }
        cout << 2*k*i + 2 * j + 1;
      }
      cout << "\n";
      for (int j = 0; j < k; j++)
      {
        if (j != 0)
        {
          cout << " ";
        }
        cout << 2*k*i + 2 * j + 2;
      }
      cout << "\n";
    }
  }
  else
  {
    cout << "No\n";
  }
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
