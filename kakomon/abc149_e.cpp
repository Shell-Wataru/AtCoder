#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

ll take_points(ll l, ll r, ll M, vector<ll> &A, vector<ll> &count_sums)
{
    // cout << l << "-" << r << endl;
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    ll count = 0;
    for (int i = 0; i <= 100000; i++)
    {
        if (A[i] == 0)
        {
            continue;
        }
        ll target = max(center - i, 0ll);
        if (target > i)
        {
            continue;
        }
        count += (count_sums[i] - count_sums[target]) * A[i] * 2;
        count += A[i] * (A[i] - 1);
        count += A[i];
    }
    if (count >= M)
    {
        return take_points(center, r, M, A, count_sums);
    }
    else
    {
        return take_points(l, center, M, A, count_sums);
    }
}

int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> A(100001, 0);
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        A[a]++;
    }
    vector<ll> total_sums(100002, 0);
    vector<ll> count_sums(100002, 0);
    for (ll i = 0; i < 100001; i++)
    {
        total_sums[i + 1] = total_sums[i] + i * A[i];
        count_sums[i + 1] = count_sums[i] + A[i];
    }
    ll min_p = take_points(0, numeric_limits<ll>::max(), m, A, count_sums);
    ll count = 0;
    ll ans = 0;
    for (ll i = 0; i <= 100000; i++)
    {
        if (A[i] == 0)
        {
            continue;
        }
        ll target = max(min_p - i, 0ll);
        if (target > i)
        {
            continue;
        }
        ll current_count = 0;
        current_count += (count_sums[i] - count_sums[target]) * A[i] * 2;
        ans += (total_sums[i] - total_sums[target]) * A[i] * 2;
        ans += i * (count_sums[i] - count_sums[target]) * A[i] * 2;
        current_count += A[i] * (A[i] - 1);
        ans += i * A[i] * (A[i] - 1) * 2;
        current_count += A[i];
        ans += i * A[i] * 2;
        count += current_count;
        // cout << i << ":" << ans << endl;
    }
    // cout << min_p << endl;
    // cout << count << endl;
    cout << ans - min_p * (count - m) << endl;

    return 0;
}

int main()
{
    // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}