
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
  ll n,x,t;
  scanf("%lld",&n);
  scanf("%lld",&x);
  scanf("%lld",&t);
  ll normal = min(t/x,n-1);
  cout << normal * (normal + 1)/2 + normal * (n-normal - 1) << endl;
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