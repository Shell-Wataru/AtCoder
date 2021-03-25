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
        scanf("%lld", &A[i]);
    }
    vector<ll> jump_intos(n + 1, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            jump_intos[i] += jump_intos[i - 1];
        }
        ans += max(A[i] - 1 - jump_intos[i], 0ll);
        ll total_jumps = max(jump_intos[i], A[i] - 1);
        ll remain = total_jumps - (A[i] - 1);
        if (i + 1 < n)
        {
            jump_intos[i + 1] += remain;
        }
        if (i + 2 < n)
        {
            jump_intos[i + 2] += 1 - remain;
        }
        if (i + A[i] + 1 < n)
        {
            jump_intos[i + A[i] + 1] += -1;
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
