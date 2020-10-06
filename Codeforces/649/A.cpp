#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n, x;
  scanf("%lld%lld", &n, &x);
  // cout << n << x << endl;
  vector<ll> A(n);
  ll total = 0;
  ll first_non_x = -1;
  ll last_non_x = -1;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &A[i]);
    total += A[i];
    if (A[i] % x != 0)
    {
      if (first_non_x == -1){
        first_non_x = i;
      }
      last_non_x = i;
    }
  }
  if (total % x != 0)
  {
    cout << n << endl;
  }
  else if (first_non_x != -1)
  {
    cout << n - min(first_non_x + 1,n - last_non_x ) << endl;
  }
  else
  {
    cout << -1 << endl;
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
  return 0;
}