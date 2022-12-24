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
  ll n;
  cin >> n;
  if (n % 3 == 0){
    cout << n/3 << "\n";
  }else if(n == 1){
    cout << 2 << "\n";
  }else if(n % 3 == 1){
    cout << n/3 + 1 << "\n";
  }else{
    cout << n/3 + 1 << "\n";
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