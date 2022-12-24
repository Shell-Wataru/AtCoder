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
  ll total = 0;
  for(int i = 0;i < 4;i++){
    ll a;
    cin >> a;
    total += a;
  }
  if (total == 0){
    cout << 0 << "\n";
  }else if (total == 4){
    cout << 2 << "\n";
  }else{
    cout << 1 << "\n";
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