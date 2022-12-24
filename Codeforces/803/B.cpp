#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll ans = 0;
  for(int i = 1;i < n-1;i++){
    if (a[i] > a[i-1]+a[i+1]){
      ans++;
    }
  }
  if (k == 1){
    cout << (n-1)/2 << "\n";
  }else{
    cout << ans << "\n";
  }

  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}