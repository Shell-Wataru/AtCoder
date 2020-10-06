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

ll diff(ll n){
  string s = to_string(n);
  ll min_n = 10;
  ll max_n = -1;
  for(auto &c:s){
    min_n = min(min_n, (ll)(c- '0'));
    max_n = max(max_n, (ll)(c- '0'));
  }
  return max_n * min_n;
}
int solve()
{
  ll n,k;
  cin >> n >> k;
  ll index = 0;
  while(diff(n) != 0 && index < k-1){
    index++;
    n += diff(n);
  }
  cout << n << endl;
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