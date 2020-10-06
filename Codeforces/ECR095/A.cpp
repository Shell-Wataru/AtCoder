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
  ll x,y,k;
  cin >> x >> y >> k;
  ll needs = k * y + k - 1;
  ll increase = x-1;
  ll xtrades = (needs+ increase - 1)/increase;
  // cout << needs << endl;
  cout << k + xtrades << endl;
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