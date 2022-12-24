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
  string S1;
  string S2;
  cin >> S1;
  cin >> S2;
  map<ll, ll> colors;
  for (auto c : S1)
  {
    colors[c - 'a']++;
  }
  for (auto c : S2)
  {
    colors[c - 'a']++;
  }
  cout << colors.size() - 1 << endl;
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