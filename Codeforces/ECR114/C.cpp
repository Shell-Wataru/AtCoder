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
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  ll total = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    total += a[i];
  }
  sort(a.begin(), a.end());
  ll dragons;
  scanf("%lld", &dragons);
  for (int i = 0; i < dragons; i++)
  {
    ll x, y;
    scanf("%lld", &x);
    scanf("%lld", &y);
    auto iter = lower_bound(a.begin(), a.end(), x);
    if (iter == a.end()){
      ll attack1 = a.back();
      if (total - attack1 >= y){
        cout << x - attack1 << "\n";
      }else{
        cout << x + y - total << "\n";
      }
    }else{
      ll attack1  = *iter;
      if (total - attack1 >= y)
      {
        cout << 0 << "\n";
      }
      else if (attack1 == a[0])
      {
        cout << y - (total - attack1) << "\n";
      }
      else
      {
        iter--;
        ll attack2 = *iter;
        ll attack1_score =  max(x-attack1,0ll)+ max(y- (total-attack1),0ll);
        ll attack2_score =  max(x-attack2,0ll)+ max(y- (total-attack2),0ll);
        cout << min(attack1_score,attack2_score) << "\n";
      }

    }
  }
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
