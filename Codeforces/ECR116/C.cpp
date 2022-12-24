#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = my_pow(x, y / 2);
        ll yy = (y_2 * y_2);
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return yy * x;
        }
    }
}

int solve()
{
  ll n,k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  a.push_back(18);
  ll ans = 0;
  k++;
  for(int i = 0;i < n;i++){
    ll maximum = (my_pow(10,a[i+1]) - my_pow(10,a[i]))/my_pow(10,a[i]);
    ll use = min(k,maximum);
    k -= use;
    ans += use * my_pow(10,a[i]);
  }
  // cout << k << endl;
  cout << ans << "\n";
  return 0;
}
int main()
{
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
