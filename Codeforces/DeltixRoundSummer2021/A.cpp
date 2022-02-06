#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll c,d;
  cin >> c  >> d;
  if (c == d){
    if ( c== 0){
      cout << 0 << "\n";
    }else{
      cout << 1 << "\n";
    }
  }else if ((c-d) % 2 == 0){
    cout << 2 << "\n";
  }else{
    cout << -1 << "\n";
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