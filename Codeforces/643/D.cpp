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
ll BASE_NUM = 998244353;

int solve()
{
  ll n, s;
  cin >> n >> s;
  if (2 * n <= s)
  {
    cout << "YES" << endl;
    for (int i = 0; i < n - 1; i++)
    {
      if (i != 0)
      {
        cout << " ";
      }
      cout << 2;
    }
    if (n > 1)
    {
      cout << " ";
    }
    cout << s - 2 * n + 2 << endl;
    cout << 1 << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}