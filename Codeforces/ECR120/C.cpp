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
  ll n,k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a.begin(),a.end());
  vector<ll> sum_a(n+1);
  for(int i = 0;i < n;i++){
    sum_a[i+1] = sum_a[i] + a[i];
  }

  if (sum_a[n] <= k){
    cout << 0 << "\n";
    return 0;
  }
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i < n;i++){
    ll remain = k - (sum_a[n-i] - sum_a[1]);
    // cout << remain << endl;
    if (remain >= 0){
      ll target = min(remain/(i+1),a[0]);
      ans = min(ans,i + a[0] - target);
    }else{
      ll target = min((remain-i)/(i+1),a[0]);
      ans = min(ans,i + a[0] - target);
    }

  }
  cout << ans << "\n";
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
