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

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> presum(n+1);
  vector<ll> a(n,0);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    presum[i+1] += presum[i] + a[i];
  }
  ll ans = 0;
  vector<ll> max_values(n+1,numeric_limits<ll>::max());
  bool found = true;
  ll k = 0;
  while(found){
    found = false;
    k++;
    vector<ll> next_max_values(n+1,0);
    for(int i = n-k;i >= 0;i--){
      ll sum = presum[i+k] - presum[i];
      next_max_values[i] = max(next_max_values[i+1],next_max_values[i]);
      if (sum < max_values[i+k]){
        next_max_values[i] = max(next_max_values[i],sum);
        found = true;
      }
    }
    swap(next_max_values,max_values);
  }
  cout << k - 1<< "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
