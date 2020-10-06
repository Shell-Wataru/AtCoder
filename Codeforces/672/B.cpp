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
  vector<ll> A(n);
  ll ans = 0;
  vector<ll> highest_onebits(60);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
    ll highest_onebit = 0;
    while((A[i]>> highest_onebit) > 1){
      highest_onebit++;
    }
    ans += highest_onebits[highest_onebit];
    highest_onebits[highest_onebit]++;
  }
  cout << ans << endl;
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
  return 0;
}
