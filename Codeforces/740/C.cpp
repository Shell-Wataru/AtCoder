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
  ll n, k;
  scanf("%lld", &n);
  vector<pair<ll,ll>> caves(n);
  for(int i = 0;i < n;i++){
    ll k;
    scanf("%lld",&k);
    ll max_power = 0;
    for(int j = 0;j < k;j++){
      ll a;
      scanf("%lld",&a);
      max_power= max(max_power,a-j);
    }
    caves[i] = {max_power,k};
  }
  sort(caves.begin(),caves.end());
  ll ans = 0;
  ll beat_power = 0;
  for(int i =0;i< n;i++){
    if (ans + beat_power > caves[i].first){
      beat_power += caves[i].second;
    }else{
      ans += caves[i].first - (ans + beat_power) + 1;
      beat_power += caves[i].second;
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
