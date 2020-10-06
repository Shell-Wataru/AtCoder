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
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n,l;
    scanf("%lld", &n);
    scanf("%lld", &l);
    vector<ll> A(n+2,0);
    for (size_t i = 1; i <= n; i++)
    {
        scanf("%lld",&A[i]);
    }
    A[n+1] = l;
    ll f_at = 0;
    ll s_at = n+1;
    double f_time = 0;
    double s_time = 0;
    double f_speed = 1;
    double s_speed = 1;
    while(f_at + 1 < s_at){
        if (f_time + (A[f_at+1] - A[f_at])/f_speed < s_time + (A[s_at] - A[s_at-1])/s_speed ){
            f_time += (A[f_at+1] - A[f_at])/f_speed;
            f_speed++;
            f_at++;
        }else{
            s_time += (A[s_at] - A[s_at-1])/s_speed;
            s_speed++;
            s_at--;
        }
    }
    if (f_time < s_time){
        double remain = A[s_at] - (A[f_at] + f_speed * (s_time - f_time));
        cout  << fixed << s_time + remain/(f_speed + s_speed) << "\n";
    }else{
        double remain = A[s_at] - (A[f_at] + s_speed * (f_time - s_time));
        cout << fixed << setprecision(12) << f_time + remain/(f_speed + s_speed) << "\n";
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
