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
  ll n;
  string S;
  char c;
  scanf("%lld", &n);
  cin >> c;
  cin >> S;
  string ans(n, c);
  if (S == ans)
  {
    cout << 0 << "\n";
    return 0;
  }
  else
  {
    vector<ll> can_use(n + 1, true);
    can_use[0] = false;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; i * j <= n; j++)
      {
        if (S[i * j - 1] != c)
        {
          can_use[i] = false;
        }
      }
    }
    ll one_shot_number = -1;
    for (int i = 1; i <= n; i++)
    {
      if (can_use[i])
      {
        one_shot_number = i;
        break;
      }
    }
    if (one_shot_number == -1)
    {
      cout << 2 << "\n";
      cout << n - 1 << " " << n << "\n";
    }
    else
    {
      cout << 1 << "\n";
      cout << one_shot_number << "\n";
    }
    return 0;
  }
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
