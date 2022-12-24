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
  ll l1,r1,l2,r2;
  cin >>  l1 >> r1 >> l2 >> r2;
  if (l2 <= r1 &&  l1 <= r2){
    cout << max(l1,l2) << "\n";
  }else{
    cout << l1 + l2 << "\n";
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