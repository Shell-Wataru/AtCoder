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

ll BASE_NUM = 1000000007;
int solve()
{
  ll n,a,b;
  cin >> a >> b >> n;
  ll min_times  = BASE_NUM;
  if (a > b){
    swap(a,b);
  }
  ll base = 0;
  while(a <= n){
    // cout << a << " " << b << endl;
    // cout << base << endl;
    // cout << (b - a + b - 1)/b << endl;
    min_times = min(min_times,base + (n - a + b)/b);
    min_times = min(min_times,base + (n - b + a)/a);

    ll adds = max((b - a + b - 1)/b,1ll);
    base += adds;
    a += adds * b;
    swap(a,b);
  }
  cout << min_times << endl;
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