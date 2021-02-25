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

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  if (n == 1){
    cout << 0 << endl;
  }else if (n == 2){
    cout << 1 << endl;
  }else if (n == 3){
    cout << 2 << endl;
  }else if (n % 2 == 0){
    cout << 2 << endl;
  }else{
    cout << 3 << endl;
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