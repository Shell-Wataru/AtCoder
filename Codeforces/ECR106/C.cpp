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

int solve()
{
    ll n;
    scanf("%lld", &n);
    ll horizontal_min = numeric_limits<ll>::max();
    ll horizontal_sum = 0;
    ll vertical_min = numeric_limits<ll>::max();
    ll vertical_sum = 0;
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < n;i++){
        ll a;
        scanf("%lld",&a);
        if (i % 2 == 0){
            if (horizontal_min > a){
                if (horizontal_min != numeric_limits<ll>::max()){
                    horizontal_sum  += horizontal_min;
                }

                horizontal_min = a;
            }else{
                horizontal_sum += a;
            }
        }else{
            if (vertical_min > a){
                if (vertical_min != numeric_limits<ll>::max()){
                    vertical_sum  += vertical_min;
                }

                vertical_min = a;
            }else{
                vertical_sum += a;
            }
        }
        if (i >= 1){
            ll horizontal_lines = (i+2)/2;
            ll vertical_lines = (i+1)/2;
            // cout << i << "===" << endl;
            // cout << horizontal_min << endl;
            // cout << horizontal_sum << endl;
            // cout << vertical_min << endl;
            // cout << vertical_sum << endl;
            ll current = horizontal_min * (n - horizontal_lines + 1)  + horizontal_sum + vertical_min * (n - vertical_lines + 1)  + vertical_sum ;
            // cout << current << endl;
            ans = min(ans, current);
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
