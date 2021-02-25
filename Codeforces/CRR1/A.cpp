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
  ll x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 || y1 == y2){
    cout << abs(x2 - x1) + abs(y2 - y1) << endl;
  }else{
    cout << abs(x2 - x1) + abs(y2 - y1) + 2<< endl;
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