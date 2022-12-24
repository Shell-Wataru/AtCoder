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
#include <numeric>
using namespace std;
using ll = long long;



ll three_search(vector<ll> &my_values,ll lcm,ll b, ll l, ll r)
{
    // cout << l << "~" << r << endl;
    if (l + 2 >= r)
    {
        vector<pair<ll, ll>> values;
        for (int i = l; i < r; i++)
        {
            values.push_back({my_values[b+lcm*i], i});
        }
        sort(values.rbegin(), values.rend());
        return values.front().second;
    }
    else
    {
        ll t1 = (2 * l + r) / 3;
        ll t2 = (l + 2 * r) / 3;
        ll t1_value = my_values[b+lcm*t1];
        ll t2_value = my_values[b+lcm*t2];
        if (t1_value >= t2_value)
        {
            return three_search(my_values,lcm,b, l, t2);
        }
        else
        {
            return three_search(my_values,lcm,b, t1, r);
        }
    }
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int solve()
{
  ll n;
  cin >> n;
  vector<pair<ll,ll>> ab(n);
  ll total_a = 0;
  vector<ll> diffs;
  for(int i = 0;i < n;i++){
    scanf("%lld",&ab[i].first);
    scanf("%lld",&ab[i].second);
    total_a += ab[i].first;
    diffs.push_back(ab[i].second - ab[i].first);
  }
  sort(diffs.rbegin(),diffs.rend());
  vector<ll> values(n+1);
  values[0] = total_a;
  for(int i = 0;i < n;i++){
    values[i+1] = values[i]+diffs[i];
  }
  ll m;
  scanf("%lld",&m);
  for(int i = 0;i < m;i++){
    ll x,y;
    scanf("%lld",&x);
    scanf("%lld",&y);
    if (n % gcd(x,y) != 0){
      cout << -1 << "\n";
    }else{
      ll a,b;
      extGCD(x,y,a,b);
      a *=  n/gcd(x,y);
      b *=  n/gcd(x,y);
      ll lcm = x*y/gcd(x,y);
      if (b < 0){
        ll add = (abs(b*y)+lcm-1)/lcm * lcm;
        b += add/y;
        a -= add/x;
      }else{
        ll sub = b*y/lcm * lcm;
        b -= sub/y;
        a += sub/x;
      }
      // cout << a*x << " " << b*y << endl;
      // cout << lcm << endl;
      // cout << a*x/lcm + 1 << endl;
      if (a < 0){
        cout << -1 << "\n";
      }else{
        ll t = three_search(values,lcm,b*y,0,a*x/lcm + 1);
        cout << values[b*y+lcm*t] << "\n";
      }
    }
  }
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
