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
  ll n,m;
  scanf("%lld", &n);
  vector<ll> a(n);
  ll minimum = numeric_limits<ll>::max();
  bool all_one = true;
  bool contains_one = false;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a.begin(),a.end());
  if (can_make_zero(a) || can_make_ones(a)){
    cout << "Yes\n";
  }else{
    cout << "No\n";
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
