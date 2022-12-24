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

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);

  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  vector<ll> cumSum(n+1);
  vector<ll> fromFrontMax(n+1);
  vector<ll> fromBackMax(n+1);
  unordered_map<ll,ll> counts_from_front;
  unordered_map<ll,ll> counts_from_back;
  for(int i = 0;i < n;i++){
    cumSum[i+1] = cumSum[i] + a[i];
  }
  for(int i = 1;i <= n;i++){
    counts_from_front[cumSum[i]]++;
    fromFrontMax[i] = max(fromFrontMax[i-1],counts_from_front[cumSum[i]]);
  }
  for(int i = n;i >= 1;i--){
    counts_from_back[cumSum[i]]++;
    fromBackMax[i-1] = max(fromBackMax[i],counts_from_back[cumSum[i]]);
  }
  ll ans = 0;
  for(int i = 0;i < n;i++){
    if (a[i] == 0){
      ans = max(ans,fromFrontMax[i-1]+fromBackMax[i+1]);
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
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
