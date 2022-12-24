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
  ll n;
  scanf("%lld",&n);
  vector<ll> b(n-1);
  vector<ll> c(n);
  for(int i = 0;i < n;i++){
    cin >> c[i];
  }
  for(int i = 0;i < n-1;i++){
    cin >> b[i];
  }
  ll q;
  scanf("%lld",&q);
  for(int i = 0;i < q;i++){
    ll x;
    scanf("%lld",&x);


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
  // cout << flush;
  return 0;
}