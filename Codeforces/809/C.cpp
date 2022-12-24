#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
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
  ll n,m;
  scanf("%lld", &n);
  vector<ll> h(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&h[i]);
  }
  if (n % 2 == 1){
    ll ans = 0;
    for(int i = 1;i < n-1;i+= 2){
      ll to = max(h[i-1],h[i+1])+1;
      ans += max(0ll, to - h[i]);
    }
    cout << ans << endl;
  }else{
    vector<ll> from_left(n);
    vector<ll> from_right(n);
    for(int i = 1;i < n;i++){
      if (i % 2== 0){
        from_left[i] += from_left[i-1];
      }else{
        ll to = max(h[i-1],h[i+1])+1;
        from_left[i] += from_left[i-1] + max(0ll, to - h[i]);
      }
    }
    for(int i = 1;i < n;i++){
      if (i % 2== 0){
        from_right[n-1-i] += from_right[n-1-i+1];
      }else{
        ll to = max(h[n-1-i-1],h[n-1-i+1])+1;
        from_right[n-1-i] += from_right[n-1-i+1] + max(0ll, to - h[n-1-i]);
      }
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < n;i++){
      if (i % 2 == 0){
        ans = min(ans,from_left[i]+from_right[i+1]);
      }
    }
    cout <<  ans << "\n";
  }

  return 0;
}

int main()
{
  // cout << "!" << endl;
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
