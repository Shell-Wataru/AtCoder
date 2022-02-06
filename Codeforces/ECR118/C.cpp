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

ll ans(vector<ll> &a,ll h,ll l,ll r){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
  ll hit = 0;
  for(int i = 0;i < a.size()-1;i++){
    hit += min(a[i+1] - a[i],center);
    if (hit >= h){
      return ans(a,h,l,center);
    }
  }

  return ans(a,h,center,r);
}
int solve()
{
  ll n,h;
  scanf("%lld", &n);
  scanf("%lld", &h);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  a.push_back(a.back()+ h);

  cout << ans(a,h,0,h) << "\n";
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
