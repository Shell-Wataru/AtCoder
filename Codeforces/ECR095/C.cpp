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
    cin >> n;
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    vector<ll> my_turn_dp(n+1,numeric_limits<ll>::max()/2);
    vector<ll> friend_turn_dp(n+1,numeric_limits<ll>::max()/2);
    friend_turn_dp[0] = 0;
    for(int i = 0;i < n;i++){
        ll next = i;
        ll nextnext = i + 1;
        ll skips = 0;
        if (A[next] == 1){
            skips++;
        }
        my_turn_dp[i+1];
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
    // cout << flush;
    return 0;
}
