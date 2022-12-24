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


double value(ll n, ll t,ll a,ll b,ll plus)
{
    return 1.0*n/plus*b + 1.0*a*(plus-1)/2;
}


ll three_search(ll n,ll t,ll a,ll b, ll l, ll r)
{
    if (l + 2 >= r)
    {
        vector<pair<double, ll>> values;
        for (int i = l; i < r; i++)
        {
            values.push_back({value(n,t,a,b,i), i});
        }
        sort(values.begin(), values.end());
        return values.front().second;
    }
    else
    {
        ll t1 = (2 * l + r) / 3;
        ll t2 = (l + 2 * r) / 3;
        double t1_value = value(n,t,a,b, t1);
        double t2_value = value(n,t,a,b, t2);
        if (t1_value <= t2_value)
        {
            return three_search(n,t,a,b, l, t2);
        }
        else
        {
            return three_search(n,t,a,b, t1, r);
        }
    }
}

int solve()
{
  ll n,s,t,a,b;
  cin >> n >> s >> t >> a >> b;
  if (s == t){
    cout << 0 << endl;
  }else if (s <= t){
    ll plus = three_search(n,t,a,b,1,t-s+1);
    // cout << plus << endl;
    cout << fixed << setprecision(12)<< min(1.0*(t-s)*a,value(n,t,a,b,plus)) << endl;
  }else{
    ll plus = three_search(n,t,a,b,1,t+1);
    cout << fixed << setprecision(12) << value(n,t,a,b,plus) << endl;
  }
  return 0;
}

int main()
{
//   ll t;
//   cin >> t;
//   for (int i = 1; i <= t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}