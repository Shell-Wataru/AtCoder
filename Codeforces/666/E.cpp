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
    ll n,r1,r2,r3,d;
    scanf("%lld", &n);
    scanf("%lld", &r1);
    scanf("%lld", &r2);
    scanf("%lld", &r3);
    scanf("%lld", &d);
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }

    vector<ll> DP(n+1,numeric_limits<ll>::max());
    vector<ll> DP2(n,numeric_limits<ll>::max());
    DP[0] = -d;
    for(int i = 0;i < n;i++){
        DP[i+1] = min(DP[i+1],DP[i] + r1 * A[i] + r3 + d);
        if (i+2 <= n){
            DP[i+2] = min(DP[i+2],DP[i] + 2 * r2 + 2 * min(r1,min(r2,r3)) + 4 *d);
        }
    }
    for(int i = 0;i < n-1;i++){
        DP2[i+1] = min(DP2[i+1],DP[i] + r2 + min(r1,min(r2,r3)) + r1 * A[i+1] + r3  + 3 *d);
    }
    // for (size_t i = 0; i < n+1; i++)
    // {
    //     cout << DP[i] << ",";
    // }
    // cout << endl;

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << DP2[i] << ",";
    // }
    // cout << endl;

    cout << min(DP[n],DP2[n-1]) << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}
