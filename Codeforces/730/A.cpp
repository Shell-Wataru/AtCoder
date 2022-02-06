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
  ll a, b;
  scanf("%lld", &a);
  scanf("%lld", &b);
  if (abs(a - b) == 0)
  {
    cout << "0 0\n";
  }
  else
  {
    ll r = abs(a - b);
    cout << abs(a - b) << " " << min(a % r, r - (a % r)) << "\n";
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