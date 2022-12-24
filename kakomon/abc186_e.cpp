#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int solve()
{
    ll N, S, K;
    cin >> N >> S >> K;
    if ((N - S) % gcd(N, K) != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        ll a = N / gcd(N, K);
        ll b = K / gcd(N, K);
        ll c = (N - S) / gcd(N, K);
        ll x,y;
        extGCD(a,b,x,y);
        x *= c;
        y *= c;
        if (y < 0){
            ll add = (-y + a -1)/a;
            x -= b*add;
            y += a*add;
        }else{
            ll subs = y/a;
            x += b*subs;
            y -= a*subs;
        }
        // cout << x << endl;
        cout << y << endl;
    }
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
