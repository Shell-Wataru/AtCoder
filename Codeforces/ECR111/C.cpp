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
ll BASE_NUM = 1000000007;

bool is_straight(ll a,ll b, ll c){
    if (a <= b && b <= c){
        return true;
    }else if (a >= b && b >= c){
        return true;
    }else{
        return false;
    }
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }
    ll ans = 2*n-1;
    for(int i = 0;i + 2< n;i++){
        if (!is_straight(a[i],a[i+1],a[i+2])){
            ans++;
        }
    }
    for(int i = 0;i + 3< n;i++){
        bool is_ok = true;
        if (is_straight(a[i],a[i+1],a[i+2])){
            is_ok = false;
        }
        if (is_straight(a[i],a[i+1],a[i+3])){
            is_ok = false;
        }
        if (is_straight(a[i],a[i+2],a[i+3])){
            is_ok = false;
        }
        if (is_straight(a[i+1],a[i+2],a[i+3])){
            is_ok = false;
        }
        if (is_ok){
            ans++;
        }
    }
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
