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

bool can_make_zero(vector<ll> &a){
  for(auto aa:a){
    if (aa == 0){
      continue;
    }else{
      return aa > 1;
    }
  }
  return true;
}

bool can_make_ones(vector<ll> &a){
  ll n = a.size();
  if (a[0] != 1){
    return false;
  }
  for(int i = n-1;i >= 1;i--){
    if (a[i] == a[i-1] + 1){
      return false;
    }
  }
  return true;
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  string a,b;
  cin >> a >> b;
  ll diff = 0;
  for(int i = 0;i < n;i++){
    if (a[i] != b[i]){
      diff++;
    }
  }
  if (diff % n != 0){
    cout << "No" << "\n";
    return 0;
  }
  ll l = 0;
  ll r = n-1;
  ll target = 1;
  vector<pair<ll,ll>> ans;
  while(l <= r){
    if (a[l] - '0' != target){
      l++;
    }else if (a[r] - '0' != target){
      r--;
    }else{
      ans.push_back({l,r});
      target = 1-target;
      diff = n - diff;
      l++;
      r--;
    }
  }
  if (diff == n){
    ans.push_back({1,1});
    ans.push_back({0,1});
    ans.push_back({0,0});
  }
  cout << "Yes\n";
  cout << ans.size() << "\n";
  for(auto p:ans){
    cout << p.first + 1  << " " << p.second + 1<< "\n";
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
