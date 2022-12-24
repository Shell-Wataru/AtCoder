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
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);
  vector<ll> a(n);
  ll total = 0;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    total += a[i];
  }
  if (k >= n){
    if (n == 1){
      ll ans = total + k - 1;
      cout << ans << endl;
    }else{
      ll ans = total + n * (k-1) - n * (n-1)/2;
      cout << ans << endl;
    }
  }else{
    ll current = 0;
    for(int i = 0;i < k;i++){
      current += a[i];
    }
    ll maximum = current;
    for(int i = k;i < n;i++){
      current += a[i];
      current -= a[i-k];
      maximum = max(maximum,current);
    }
    ll ans = maximum + k*(k-1)/2;
    cout << ans << endl;
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