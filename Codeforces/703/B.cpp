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
  ll n;
  cin >> n;
  vector<ll> xs(n);
  vector<ll> ys(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&xs[i]);
    scanf("%lld",&ys[i]);
  }
  sort(xs.begin(),xs.end());
  sort(ys.begin(),ys.end());
  if (n % 2 == 1){
    cout << 1 << "\n";
  }else{
    ll i2 = n/2;
    ll i1 = n/2 - 1;
    cout << (xs[i2] - xs[i1] + 1) * (ys[i2] - ys[i1] + 1) << "\n";
  }
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