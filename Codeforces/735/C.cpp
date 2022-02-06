#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

ll answer(ll l, ll r,vector<ll> &a_sum,vector<ll> &b_sum){
  // cout << l << "~" << r << endl;
  if (l + 1 == r){
    return r;
  }
  ll center = (l+r)/2;
  ll n = a_sum.size()-1;
  ll take = (n+center) - (n+center)/4;
  ll b = b_sum[min(take,n)];
  ll a = 100 * min(take,center) + a_sum[take - min(take,center)];
  // cout << take << endl;
  // cout << center << endl;
  // cout << "a:" << a << endl;
  // cout << "b:" << b << endl;
  if (a >= b){
    return answer(l,center,a_sum,b_sum);
  }else{
    return answer(center,r,a_sum,b_sum);
  }
}
int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  if (n > m){
    cout << 0 << "\n";
  }else{
    ll ans = n;
    for(int i = 59;i >= 0;i--){
      if ((ans| (1ll<<i)) <= m ){
        ans |= 1ll<<i;
      }
    }
    cout << ans + 1 << "\n";
  }
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
