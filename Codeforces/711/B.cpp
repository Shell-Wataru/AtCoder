#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,W;
  scanf("%lld",&n);
  scanf("%lld",&W);
  vector<ll> ws(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&ws[i]);
  }
  vector<ll> counts(31,0);
  for(int i = 0;i < n;i++){
    ll k = 0;
    while(!(ws[i] & 1<< k)){
      k++;
    }
    counts[k]++;
  }
  ll ans = 0;
  bool all_zero = false;
  while(!all_zero){
    all_zero = true;
    ans++;
    ll capacity = 0;
    for(int i = 30; i >= 0;i--){
      capacity *= 2;
      if (W & 1<<i){
        capacity += 1;
      }
      ll deletes = min(counts[i],capacity);
      counts[i] -= deletes;
      capacity -= deletes;
      if (counts[i] != 0){
        all_zero = false;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}