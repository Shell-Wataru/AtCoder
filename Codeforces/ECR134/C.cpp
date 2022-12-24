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
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  for(int i = 0;i < n;i++){
    cin >> b[i];
  }
  map<ll,ll> targets;
  vector<ll> d_min(n);
  vector<ll> d_max(n);
  ll remain = 0;
  for(int i = n-1;i >= 0;i--){
    while(!b.empty() && b.back() >= a[i]){
      targets[b.back()]++;
      remain++;
      b.pop_back();
    }
    ll target_max = targets.rbegin()->first;
    ll target_min = targets.begin()->first;
    d_max[i] = target_max - a[i];
    d_min[i] = target_min - a[i];
    remain--;
    if (remain == 0){
      targets.clear();
    }

  }
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout <<  " ";
    }
    cout << d_min[i];
  }
  cout  << "\n";
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout <<  " ";
    }
    cout << d_max[i];
  }
   cout << "\n";
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
