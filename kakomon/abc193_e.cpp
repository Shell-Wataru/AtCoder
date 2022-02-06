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

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
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

int solve(){
    ll X,Y,P,Q;
    cin >> X >> Y >> P >> Q;
    ll ans = numeric_limits<ll>::max();
    ll a = 2*X + 2*Y;
    ll b =  - P - Q;
    ll gcd_ab = gcd(a,b);
    ll n,m;
    ll ext_gcd_ab = extGCD(a,b,n,m);
    if (ext_gcd_ab < 0){
        n *= -1;
        m *= -1;
    }
    ll diff_n = - b /gcd_ab;
    ll diff_m = a /gcd_ab;
    // cout << a << b << n  << ","<< m<< endl;
    // cout << gcd_ab << endl;
    for(int y = 0;y < Y;y++){
        ll target = P - X - y;
        if (target % gcd_ab == 0){
            ll base_n = n * (target/gcd_ab);
            ll base_m = m * (target/gcd_ab);
            if (base_n < 0){
                ll add_count = (- base_n + diff_n - 1)/diff_n;
                base_n += diff_n*add_count;
                base_m += diff_m*add_count;
            }else{
                ll add_count = base_n/diff_n;
                base_n -= diff_n*add_count;
                base_m -= diff_m*add_count;
            }
            // cout << base_n << "-"  << base_m << endl;
            ans = min(ans,base_n * a + X + y);
        }
    }
    for(int q = 0;q < Q;q++){
        ll target = P + q - X;
        if (target % gcd_ab == 0){
            ll base_n = n * (target/gcd_ab);
            ll base_m = m * (target/gcd_ab);
            if (base_n < 0){
                ll add_count = (- base_n + diff_n - 1)/diff_n;
                base_n += diff_n*add_count;
                base_m += diff_m*add_count;
            }else{
                ll add_count = base_n/diff_n;
                base_n -= diff_n*add_count;
                base_m -= diff_m*add_count;
            }
            // cout << base_n << "-"  << base_m << endl;
            ans = min(ans,base_n * a + X);
        }
    }
    if (ans== numeric_limits<ll>::max()){
        cout << "infinity" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}
int main()
{
  ll T;
  cin >> T;
  for(int i = 0;i < T;i++){
      solve();
  }
//   cout << flush;
  return 0;
}
