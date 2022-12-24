#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  map<ll,ll> counts;
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
    counts[a[i]]++;
  }
  ll maximum = 0;
  for(auto p:counts){
    maximum = max(maximum,p.second);
  }
  // cout << maximum << endl;
  ll ans = 0;
  while(maximum < n){
    ans += 1;
    ans += min(n - maximum,maximum);
    maximum *= 2;
  }
  cout << ans  << "\n";
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