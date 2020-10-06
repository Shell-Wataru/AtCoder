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
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll total_time = b;
  ll total_sleep = b;
  if (b >= a){
    cout << total_time << endl;
  }else{
    if (c > d){
      ll one_period_sleep = c - d;
      ll one_period = c;
      ll periods =  (a - total_sleep + one_period_sleep - 1)/one_period_sleep;
      cout << total_time + one_period * periods << endl;
    }else{
      cout << -1 << endl;
    }
  }

  // cout << n << endl;
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