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

ll BASE_NUM = 1000000007;
ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else if (y == 1)
    {
        return x;
    }
    else
    {
        ll y_2 = my_pow(x, y / 2) % BASE_NUM;
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
    vector<ll> a(n);
    for (int i = 1; i <= n; i++)
    {
        if (n - i == 0)
        {
            cout << 10;
        }
        else
        {
            ll a = 2 * my_pow(10,n - i - 1) * 9;
            ll b = (n - i - 1) * my_pow(10,n - i - 2) * 9 * 9
            cout << 2 * my_pow(10,n - i - 1) * 9 + ;
        }
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}