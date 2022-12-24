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
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll ans = 0;
  vector<ll> nonzero;
  vector<pair<ll,ll>> onetwo;
  vector<pair<ll,ll>> twoone;
  vector<pair<ll,ll>> threeonetwo;
  vector<pair<ll,ll>> threetwoone;
  for(ll i = 0;i < n;i++){
    if (a[i] != 0){
      nonzero.push_back(i);
    }else{
      ans += (i+1)*(n-i);
    }
  }
  ll one_index = -1;
  ll two_index = -1;
  ll three_index = -1;
  for(int i = 0;i < n;i++){
    if(a[i] == 0){
      continue;
    }else if (one_index == -1){
       if(a[i] == 1){
        one_index = i;
       }

    }else{
      if(a[i] == 2){
        onetwo.push_back({one_index,i});
        one_index = -1;
      }else if (a[i] == 1){
        continue;
      }else{
        one_index = -1;
      }
    }
  }

  one_index = -1;
  two_index = -1;
  three_index = -1;
  for(int i = 0;i < n;i++){
    if(a[i] == 0){
      continue;
    }else if (two_index == -1){
       if(a[i] == 2){
        two_index = i;
       }

    }else{
      if(a[i] == 1){
        twoone.push_back({two_index,i});
        two_index = -1;
      }else if (a[i] == 2){
        continue;
      }else{
        two_index = -1;
      }
    }
  }

  one_index = -1;
  two_index = -1;
  three_index = -1;
  for(int i = 0;i < n;i++){
    if(a[i] == 0){
      continue;
    }else if (three_index == -1){
       if(a[i] == 3){
        three_index = i;
       }
    }else if(one_index == -1){
      if (a[i] == 1){
        one_index = i;
      }else if (a[i] == 2){
        three_index = -1;
      }else{
        continue;
      }
    }else {
      if(a[i] == 1){
        continue;
      }else if(a[i] == 2){
        threeonetwo.push_back({three_index,i});
        three_index = -1;
        one_index = -1;
      }else{
        three_index = -1;
        one_index = -1;
      }
    }
  }

  one_index = -1;
  two_index = -1;
  three_index = -1;
  for(int i = 0;i < n;i++){
    if(a[i] == 0){
      continue;
    }else if (three_index == -1){
       if(a[i] == 3){
        three_index = i;
       }
    }else if(two_index == -1){
      if (a[i] == 1){
        three_index = -1;
      }else if (a[i] == 2){
        two_index = i;
      }else{
        continue;
      }
    }else {
      if(a[i] == 1){
        threetwoone.push_back({three_index,i});
        three_index = -1;
        two_index = -1;
      }else if(a[i] == 2){
        continue;
      }else{
        three_index = -1;
        two_index = -1;
      }
    }
  }
  nonzero.push_back(n);
  onetwo.push_back({n,n});
  twoone.push_back({n,n});
  threeonetwo.push_back({n,n});
  threetwoone.push_back({n,n});
  // cout << ans << endl;
  for(ll i = 0;i < n;i++){
    ll a = *lower_bound(nonzero.begin(),nonzero.end(),i);
    pair<ll,ll> b;
    pair<ll,ll> c;
    auto onetwo_range = *lower_bound(onetwo.begin(),onetwo.end(),make_pair(i,-1ll));
    auto twoone_range = *lower_bound(twoone.begin(),twoone.end(),make_pair(i,-1ll));
    if (onetwo_range < twoone_range){
      b = onetwo_range;
      auto iter = lower_bound(threetwoone.begin(),threetwoone.end(),make_pair(b.second+1,-1ll));
      if (iter != threetwoone.end()){
        c = *iter;
      }else{
        c = {n,n};
      }

    }else{
      b = twoone_range;
      auto iter = lower_bound(threeonetwo.begin(),threeonetwo.end(),make_pair(b.second+1,-1ll));
      if (iter != threeonetwo.end()){
        c = *iter;
      }else{
        c = {n,n};
      }
    }
    // cout << "1:" << a << "~" << b.second-1 << endl;
    // cout << "2:" << b.second << "~" << c.second-1 << endl;
    // cout << "3:" << c.second << "~" << n << endl;
    // cout << "==" << endl;
    cout << ans << endl;
    ans += 1* (b.second- a) + 2*(c.second-b.second) + 3*(n-c.second);
  }
  cout << ans << endl;
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
