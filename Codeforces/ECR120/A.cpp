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

bool can_make(ll l1,ll l2,ll l3){
  if (l1 == l2 && l3 % 2 == 0){
    return true;
  }
  if (l1 + l2 == l3){
    return true;
  }
  return false;
}
int solve()
{
  ll l1,l2,l3;
  cin >> l1 >> l2 >> l3;
  if (can_make(l1,l2,l3) || can_make(l3,l1,l2) || can_make(l2,l3,l1)){
    cout << "Yes\n";
  }else{
    cout << "No\n";
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