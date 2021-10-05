
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
  ll a,b;
  scanf("%lld",&a);
  scanf("%lld",&b);
  if (b == 1){
    cout << "NO" << "\n";
  }else{
    cout << "YES\n";
    cout << a*b << " " << a << " " << a*(b+1) << "\n";
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