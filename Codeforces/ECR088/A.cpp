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
  ll n,m,k;
  cin >> n >> m >> k;
  ll winner_joker = min(n/k,m);
  ll loser_joker = (m - winner_joker + (k-2))/(k-1);
  // cout << winner_joker << " " << loser_joker << endl;
  cout << winner_joker - loser_joker << endl;
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