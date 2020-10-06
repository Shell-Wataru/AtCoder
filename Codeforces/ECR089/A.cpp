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
  ll ans = 0;
  cin >> a >> b;
  if (a > b){
    swap(a,b);
  }
  if (a >= b/2){
    ans = (a + b)/3;
  }else{
    ans = a;
  }
  cout << ans << endl;
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