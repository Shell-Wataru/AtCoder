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
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for(int i =0 ;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll ans = 0;
  for(int i = 0;i < n;i+=2){
    ll l = 0;
    ll r = a[i] - 1;
    ll current_depth = a[i];
    for(int j = i+1;j < n;j++){
      if (j % 2 == 1){
        ll new_depth = current_depth - a[j];
        ans += max(r - max(new_depth,l) + 1,0ll);
        r = min(r,new_depth);
        current_depth = new_depth;
      }else{
        current_depth = current_depth + a[j];
      }
    }
  }
  cout << ans << "\n";
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
