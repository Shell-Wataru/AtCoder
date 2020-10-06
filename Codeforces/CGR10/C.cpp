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
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    ll ans = 0;
    for(int i = n-1;i >= 1;i--){
        if (A[i] < A[i-1]){
            ans += A[i-1] - A[i];
        }
    }
    cout << ans << endl;
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
