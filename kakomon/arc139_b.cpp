#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

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
    ll N, X, A, Y, B, Z;
    cin >> N >> A >> B >> X >> Y >> Z;
    ll NN = N;
    vector<pair<ll, ll>> operations = {
        {1, X}, {A, Y}, {B, Z}};
    sort(operations.begin(), operations.end(), [](pair<ll, ll> l, pair<ll, ll> r)
         { return l.second * r.first < r.second * l.first; });
    ll ans = 0;
    for(int i = 0;i < 3;i++){
        ans += NN/operations[i].first * operations[i].second;
        NN %= operations[i].first;
    }
    if (operations[2].first == 1){
        if (N/operations[0].first < operations[0].first){
            for(int i = 0;i <= N/operations[0].first;i++){
                // cout << i << endl;
                ans = min(ans,operations[0].second * i + (N- operations[0].first*i)/operations[1].first * operations[1].second + ((N- operations[0].first*i)% operations[1].first) * operations[2].second);
            }
        }else{
            ll a = operations[0].first;
            ll b = operations[1].first;
            ll g = gcd(a,b);
            for(int i = 0;i < a;i++){
                if ( (N-i) % g != 0){
                    continue;;
                }else{
                    ll x,y;
                    extGCD(a,b,x,y);
                    x *= (N-i)/g;
                    y *= (N-i)/g;
                    if (y < 0){
                        ll add = (-y + a/g - 1)/(a/g);
                        x -= b/g * add;
                        y += a/g * add;
                    }else{
                        ll sub = y/(a/g);
                        x += b/g * sub;
                        y -= a/g * sub;
                    }
                    // cout << x << "*" << a << "+" << y << "*"  << b << "+" << i<< endl;
                    if (x >= 0 && y >= 0){
                        ans = min(ans,x*operations[0].second + y*operations[1].second + i*operations[2].second);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
