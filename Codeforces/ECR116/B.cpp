#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    ll ans = 0;
    ll current = 1;
    while(current < n && current <= k ){
        current *= 2;
        ans++;
    }
    if (current <= n){
        ans += (n-current+ k - 1)/k;
    }
    cout << ans << "\n";
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
