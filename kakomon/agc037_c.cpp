#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    queue<ll> removables;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i] - a[i] >= b[(n + i - 1) % n] + b[(n + i + 1) % n])
        {
            // cout << i << endl;
            removables.push(i);
        }
    }
    ll ans = 0;
    while (!removables.empty())
    {
        ll i = removables.front();
        removables.pop();
        // cout << i << endl;
        ll both_side_sum = b[(n + i - 1) % n] + b[(n + i + 1) % n];
        // cout << both_side_sum << endl;
        if ((b[i] - a[i]) / both_side_sum > 0)
        {
            ans += (b[i] - a[i]) / both_side_sum;
            b[i] = a[i] + (b[i] - a[i]) % both_side_sum;
            if (b[(n + i - 1) % n] - a[(n + i - 1) % n] >= b[(n + i - 2) % n] + b[(n + i) % n])
            {
                removables.push((n + i - 1) % n);
            }
            if (b[(n + i + 1) % n] - a[(n + i + 1) % n] >= b[(n + i + 2) % n] + b[(n + i) % n])
            {
                removables.push((n + i + 1) % n);
            }
        }
    }
    // for(int i = 0;i < n;i++){
    //     cout << b[i] << ",";
    // }
    // cout << endl;
    ll is_same = true;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != a[i])
        {
            is_same = false;
            break;
        }
    }
    if (is_same)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
