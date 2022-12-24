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
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  ll min_v = numeric_limits<ll>::max();
  ll min_i = -1;
  ll max_v = numeric_limits<ll>::min();
  ll max_i = -1;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    if (a[i] < min_v){
      min_v = a[i];
      min_i = i;
    }
    if (a[i] > max_v){
      max_v = a[i];
      max_i = i;
    }
  }
  cout << min_i + 1 << " " << max_i + 1<< "\n";
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