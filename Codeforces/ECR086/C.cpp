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
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> sums(a * b, 0);
    for (int i = 0; i < a * b; i++)
    {
        if ((i % a) % b != (i % b) % a)
        {
            sums[i] = 1;
        }
    }

    for (int i = 1; i < a * b; i++)
    {
        sums[i] += sums[i - 1];
    }
    // cout << sums[a*b -1] << endl;
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll normal_periods_start = (l + a * b - 1) / (a * b) * (a * b);
        ll normal_periods_ends = r - r % (a * b);
        // cout << l << "~" << normal_periods_start << endl;
        // cout << normal_periods_start << "~" << normal_periods_ends << endl;
        // cout << normal_periods_ends << "~" << r << endl;
        ll before = sums[a * b - 1] - sums[(l + a * b - 1) % (a * b)];
        ll normal = sums[a * b - 1] * ((normal_periods_ends - normal_periods_start) / (a * b));
        ll after = sums[r % (a * b)];
        // cout <<  before << ","<< normal  << "," << after << endl;
        if (i != 0)
        {
            cout << " ";
        }
        cout << normal + before + after;
        // ll total = 0;
        // for (int j = l; j <= r; j++)
        // {
        //     if ((j % a) % b != (j % b) % a)
        //     {
        //         total++;
        //     }
        // }
        // cout << ":" << total;
    }
    cout << endl;
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
    return 0;
}
