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
  ll a,b;
  cin >> a >> b;
  ll x = 0;
  for(int i = 0;i < 40;i++){
    if((a & (1ll<<i)) && (b & (1ll<<i))){
      x += 1ll<<i;
    }
  }
  // cout << x << endl;
  cout << (a ^ x) + (b ^ x) << endl;
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