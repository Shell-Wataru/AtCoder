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
  ll n,q,k;
  cin >> n >> q >> k;
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < q;i++){
    ll l,r;
    scanf("%lld",&l);
    scanf("%lld",&r);
    l--;
    r--;
    if (a[r] > k){
      if (r -1 >= l){
        cout << k - a[r-1] << "\n";
      }else{
        cout << k << "\n";
      }
    }else{
      cout << k + 1 + a[r] - a[l] - 2 * (r -l + 1) << "\n";
    }
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