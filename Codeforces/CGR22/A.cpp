#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,z;
  cin >> n;
  vector<ll> fire;
  vector<ll> frost;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&b[i]);
  }
  for(int i = 0;i < n;i++){
    if(a[i] == 0){
      fire.push_back(b[i]);
    }else{
      frost.push_back(b[i]);
    }
  }
  sort(fire.rbegin(),fire.rend());
  sort(frost.rbegin(),frost.rend());
  if (fire.size() != frost.size()){
    if (fire.size() < frost.size()){
      swap(fire,frost);
    }
    ll ans = 0;
    for(auto f:frost){
      ans += f*2;
    }
    for(int i = 0;i < fire.size();i++){
      if (i < frost.size()){
        ans += fire[i]*2;
      }else{
        ans += fire[i];
      }
    }
    cout << ans << "\n";
  }else{
    ll total = 0;
    for(auto f:frost){
      total += f*2;
    }
    for(auto f:fire){
      total += f*2;
    }
    cout << max(total - fire.back(), total - frost.back()) << "\n";
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