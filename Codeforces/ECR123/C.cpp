#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
  ll n,x;
  scanf("%lld",&n);
  scanf("%lld",&x);
  vector<ll> A(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&A[i]);
  }
  vector<ll> maximums(n+1,numeric_limits<ll>::min());
  maximums[0] = 0;
  for(int i = 0;i < n;i++){
    ll current = 0;
    for(int j = i;j < n;j++){
      current += A[j];
      maximums[j-i+1] = max(maximums[j-i+1],current);
    }
  }
  for(int i = 0;i <= n;i++){
    ll ans = 0;
    for(int j = 0;j <= n;j++){
      ans = max(ans,maximums[j] + min(j,i) *x);
    }
    if (i!= 0){
      cout << " ";
    }
    cout << ans;
  }
  cout << "\n";
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
