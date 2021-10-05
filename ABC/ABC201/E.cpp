#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;


int solve(){
  ll N,M;
  cin >> N >> M;
  vector<pair<ll,ll>> plus;
  vector<pair<ll,ll>> minus;
  vector<ll> zero;
  for(int i = 0;i < M;i++){
    ll x,y;
    cin >> x >> y;
    y -= N;
    if (y == 0){
      zero.push_back(x);
    }else if(y > 0){
      plus.push_back({x,y});
    }else{
      minus.push_back({x,-y});
    }
  }
  sort(zero.begin(),zero.end());
  sort(plus.begin(),plus.end());
  sort(minus.begin(),minus.end());
  bool can_go_plus = false;
  bool can_go_minus = false;
  bool can_go_zero = false;
  if (zero.size() != 0){
    if ((plus.size() != 0 && plus[0].first >= zero[0]) ||
        (minus.size() != 0 && minus[0].first >= zero[0]) ){
          can_go_plus = true;
          can_go_minus = true;
    }else{
      if((plus.size() != 0 && plus[0].first == zero[0])){
        can_go_plus = true;
      }
      if((minus.size() != 0 && minus[0].first == zero[0])){
        can_go_minus = true;
      }
      cout << 0 << endl;
      return 0;
    }
  }
  ll plus_current_x = 0;
  ll plus_current_y = 0;
  for(int i = 0;i < plus.size();i++){
    if (plus[i].first > plus_current_x && plus[i].second == plus_current_y + 1){
      plus_current_x = plus[i].first;
      plus_current_y = plus[i].second;
    }
  }

  ll minus_current_x = 0;
  ll minus_current_y = 0;
  for(int i = 0;i < minus.size();i++){
    if (minus[i].first > minus_current_x && minus[i].second == minus_current_y + 1){
      minus_current_x = minus[i].first;
      minus_current_y = minus[i].second;
    }
  }
  // cout << plus.size() << endl;
  cout << -minus_current_x << "~" << plus_current_x << endl;
  cout << plus_current_x + minus_current_x + 1 << endl;
  return 0;
}
int main()
{
  ll t = 1;
  // cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }

  return 0;
}
