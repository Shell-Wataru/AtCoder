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
  ll a,b,c;
  cin >> a >> b >> c;
  if (a * b <= c){
      cout << 1 << " " << -1 << endl;
  }else if (a * b > c){
    if (a > c){
      cout << -1 << " " << b << endl;
    }else if (a == c){
      cout << -1 << " " << b << endl;
    }else{
      cout << 1 << " " << b << endl;
    }
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