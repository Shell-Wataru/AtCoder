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
  scanf("%lld",&n);
  vector<pair<ll,ll>> monsters(n);
  for(int i = 0;i < n;i++){
    cin >> monsters[i].first;
  }
  for(int i = 0;i < n;i++){
    cin >> monsters[i].second;
  }
  ll ans = 0;
  ll last_monster_k = monsters[n-1].first;
  ll maximum_monster_k = monsters[n-1].first;
  ll maximum_monster_h = monsters[n-1].second;
  for(int i = n-2;i >= 0 ;i--){
    ll k_diff = maximum_monster_k - monsters[i].first;
    ll h_diff = maximum_monster_h - monsters[i].second;
    if (maximum_monster_h - k_diff <= 0){
      ll start_k = maximum_monster_k - maximum_monster_h;
      ll continue_count = last_monster_k - start_k;
      ans += continue_count * (continue_count+1)/2;
      last_monster_k = monsters[i].first;
      maximum_monster_k = monsters[i].first;
      maximum_monster_h = monsters[i].second;
    }else if (k_diff > h_diff){
      maximum_monster_k = monsters[i].first;
      maximum_monster_h = monsters[i].second;
    }
  }
  ll start_k = maximum_monster_k - maximum_monster_h;
  ll continue_count = last_monster_k - start_k;
  ans += continue_count * (continue_count+1)/2;
  cout << ans << endl;
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
