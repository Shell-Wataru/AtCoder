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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

ll pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2) % BASE_NUM;
        ll yy = (y_2 * y_2) % BASE_NUM;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % BASE_NUM;
        }
    }
}

int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  for(int i = 0;i < n;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  ll min_diff = numeric_limits<ll>::max();
  for(int c = 1; log2(c) * (n-1) < 60 && c < 200000;c++){
    ll diff = 0;
    for(int i = 0;i < n;i++){
      diff += abs(A[i] - pow(c,i));
    }
    min_diff =min(min_diff,diff);
  }
  cout << min_diff << endl;
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
  return 0;
}
