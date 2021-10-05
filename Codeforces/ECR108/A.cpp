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
  ll r, b, d;
  cin >> r >> b >> d;
  ll diff = abs(r - b);
  ll dishes = min(r, b);
  ll max_d = (diff + dishes - 1) / dishes;
  if (max_d <= d)
  {
    cout << "YES"
         << "\n";
  }
  else
  {
    cout << "NO"
         << "\n";
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