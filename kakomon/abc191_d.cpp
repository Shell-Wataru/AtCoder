#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

ll sqrt(ll l, ll r, ll r2)
{
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    if (center * center > r2)
    {
        return sqrt(l, center, r2);
    }
    else
    {
        return sqrt(center, r, r2);
    }
}
int solve()
{
    double _x, _y, _r;
    scanf("%lf", &_x);
    scanf("%lf", &_y);
    scanf("%lf", &_r);
    ll x = round(_x * 10000);
    ll base_x = x / 10000 * 10000;
    ll y = round(_y * 10000);
    ll r = round(_r * 10000);
    ll ans = 0;
    ll base = 1000000000000ll;
    for (int i = -((r + 9999) / 10000); i <= ((r + 9999) / 10000); i++)
    {
        // cout << i << endl;
        ll current_x = base_x + 10000 * i;
        ll r2 = r * r - (x - current_x) * (x - current_x);
        if (r2 < 0){
            continue;
        }
        // cout << r2 << endl;
        ll yd = sqrt(0, r+1, r2);
        // cout << yd << endl;
        ll min_y = y - yd + base;
        ll max_y = y + yd+ base;
        ans += max_y / 10000 - (min_y - 1) / 10000;
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    //   // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}