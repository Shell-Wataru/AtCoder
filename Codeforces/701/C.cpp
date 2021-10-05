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
    ll x,y;
    scanf("%lld",&x);
    scanf("%lld",&y);
    ll ans = 0;
    for(ll i = 1;i <= 1000000;i++){
        ll start_x = 2 * i + i * i;
        ll end_x = min(2 * i + i * (y-1),x);
        if (start_x <= end_x){
            ans += (end_x - start_x  + 1 + i - 1)/i;
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
