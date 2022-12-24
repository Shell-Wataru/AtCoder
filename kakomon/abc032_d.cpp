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
using namespace std;
using ll = long long;

ll half_all(ll n,ll W,vector<pair<ll,ll>> &goods){
    ll first_half = n/2;
    ll second_half = n - first_half;
    map<ll,ll> dp;
    for(int i = 0;i < 1ll<<first_half;i++){
        ll weight = 0;
        ll value = 0;
        for(int j = 0;j < first_half;j++){
            if (i & 1ll<<j){
                value += goods[j].first;
                weight += goods[j].second;
            }
        }
        dp[weight] = max(dp[weight],value);
    }
    ll first_half_max_value = 0;
    for(auto p:dp){
        dp[p.first] = max(dp[p.first],first_half_max_value);
        first_half_max_value = dp[p.first];
    }
    ll ans = 0;
    for(int i = 0;i < 1ll<<second_half;i++){
        ll weight = 0;
        ll value = 0;
        for(int j = 0;j < second_half;j++){
            if (i & 1ll<<j){
                value += goods[first_half + j].first;
                weight += goods[first_half + j].second;
            }
        }
        if (weight <= W){
            auto iter = dp.upper_bound(W-weight);
            iter--;
            ans = max(ans,value + iter->second);
        }
    }
    return ans;
}

ll small_w(ll n,ll W,vector<pair<ll,ll>> &goods){
    ll max_w = 1000*200;
    vector<vector<ll>> dp(n+1,vector<ll>(max_w+1,0));
    for(int i = 0;i < n;i++){
        dp[i+1] = dp[i];
        for(int j = 0;j + goods[i].second <= max_w;j++){
            dp[i+1][j + goods[i].second] = max(dp[i+1][j + goods[i].second], dp[i][j] + goods[i].first);
        }
    }
    return dp[n][min(max_w,W)];
}

ll small_v(ll n,ll W,vector<pair<ll,ll>> &goods){
    ll max_v = 1000*200;
    vector<vector<ll>> dp(n+1,vector<ll>(max_v+1,numeric_limits<ll>::max()/2));
    dp[0][0] = 0;
    for(int i = 0;i < n;i++){
        dp[i+1] = dp[i];
        for(int j = 0;j + goods[i].first <= max_v;j++){
            dp[i+1][j + goods[i].first] = min(dp[i+1][j + goods[i].first], dp[i][j] + goods[i].second);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= max_v;i++){
        if(dp[n][i] <= W){
            ans = i;
        }
    }
    return ans;
}
int solve()
{
  ll n,W;
  scanf("%lld", &n);
  scanf("%lld", &W);
  vector<pair<ll,ll>> goods(n);
  ll max_v = 0;
  ll max_w = 0;
  for(int i = 0;i < n;i++){
      cin >> goods[i].first >> goods[i].second;
      max_v = max(max_v, goods[i].first);
      max_w = max(max_w, goods[i].second);
  }
  if (n <= 30){
      cout << half_all(n,W,goods) << "\n";
  }else if (max_v <= 1000){
      cout << small_v(n,W,goods) << "\n";
  }else if (max_w <= 1000){
      cout << small_w(n,W,goods) << "\n";
  }
  return 0;
}

int main()
{
  // // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}
