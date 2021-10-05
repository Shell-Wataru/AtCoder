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
  ll n, k;
  cin >> n >> k;
  ll target;
  if (n % k == 0)
  {
    cout << 1 << endl;
  }
  else if (n < k)
  {
    cout << (k + n - 1) / n << endl;
  }
  else
  {
    cout << 2 << endl;
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