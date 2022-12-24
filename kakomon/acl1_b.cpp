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

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
// 符号に注意
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
    ll N;
    cin >> N;
    if (N == 1){
        cout << 1 << endl;
        return 0;
    }
    N *= 2;
    ll ans = N;
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ll a = i;
            ll b = N/i;
            if (gcd(a,b) == 1){
                ll x,y;
                extGCD(a,b,x,y);
                if (x < 0){
                    x = -x;
                }else{
                    y = -y;
                }
                ll removes = min(x/b,y/a);
                x -= b * removes;
                y -= a * removes;

                // cout << a*x << "," << b*y << endl;
                if (a*x < b*y){
                    ans = min(ans,a*x);
                }else{
                    ans = min(ans,b*y);
                }
            }
        }
    }
    cout << ans << endl;
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