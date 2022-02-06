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
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n,q;
  scanf("%lld",&n);
  scanf("%lld",&q);
  string S;
  cin >> S;
  vector<vector<ll>> counts(26,vector<ll>(n+1,0));
  for (size_t i = 0; i < n; i++)
  {
    counts[S[i] - 'a'][i+1]+= (S[i] - 'a')+1;
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j < 26;j++){
      counts[j][i+1] += counts[j][i];
    }
  }
  for(int i = 0;i < q;i++){
    ll l,r;
    scanf("%lld",&l);
    scanf("%lld",&r);
    l--;
    ll ans = 0;
    for(int j = 0;j < 26;j++){
      ans += counts[j][r] - counts[j][l];
    }
    cout << ans << "\n";
  }
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;

  // for (int i = 1; i <= t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}