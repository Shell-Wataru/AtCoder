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
  map<ll,ll> counts;
  ll total = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    total += a[i];
    counts[a[i]]++;
  }
  // cout << total << endl;
  if ( (2* total) % n != 0){
    cout << 0 << "\n";
  }else{
    ll ans = 0;
    ll target = 2*total/n;
    for(auto p:counts){
      ll a =  p.first;
      ll b = target - a;
      if (a == b){
        ans += p.second * (p.second-1)/2;
      }else if (a < b){
        ans += p.second * counts[b];
      }
    }
    cout << ans << "\n";
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
