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
  ll n,m;
  scanf("%lld",&n);
  scanf("%lld",&m);
  map<ll,ll> counts;
  ll ans = 0;
  for (size_t i = 0; i < n; i++)
  {
    ll a;
    scanf("%lld",&a);
    counts[a % m]++;
  }
  for(int i = 0;i <= m -i;i++){
    ll j = (m - i)% m;
    if (i == j){
      if (counts[i] > 0){
        ans++;
      }
    }else{
      if (counts[i] > 0 ||  counts[j] > 0){
        ans++;
        ll remain = max(abs(counts[i] - counts[j]) - 1,0ll);
        ans += remain;
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