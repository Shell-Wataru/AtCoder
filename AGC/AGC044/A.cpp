#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1e+9 + 7;

double lower(ll N, ll x, ll A, ll B, ll C, ll D)
{
    double max_rate = 1;
    max_rate = max(max_rate, pow(2, 1.0 / A));
    max_rate = max(max_rate, pow(3, 1.0 / B));
    max_rate = max(max_rate, pow(5, 1.0 / C));
    double max_diff = 1.0 / D;
    double xx = max_diff / (max_rate - 1);
    if (x < xx)
    {
        return (xx - x) / max_diff + log(1.0 * N / xx) / log(max_rate);
    }
    else if (x < N)
    {
        return log(1.0 * N / x) / log(max_rate);
    }
    else
    {
        return (x - N) / max_diff;
    }
}
int solve()
{
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    map<ll, ll> min_pay;
    priority_queue<pair<double, pair<ll, ll>>, vector<pair<double, pair<ll, ll>>>, greater<pair<double, pair<ll, ll>>>> q;
    double max_rate = 1;
    max_rate = max(max_rate, pow(2, 1.0 / A));
    max_rate = max(max_rate, pow(3, 1.0 / B));
    max_rate = max(max_rate, pow(5, 1.0 / C));
    double max_diff = 1.0 / D;
    ll xx = floor(max_diff / (max_rate - 1));
    q.push({D * xx + lower(N, xx, A, B, C, D), {D * xx, xx}});
    ll min_cost = numeric_limits<ll>::max() / 2;
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        double entropy = p.first;
        ll cost = p.second.first;
        ll num = p.second.second;
        if (cost < min_cost && (min_pay.find(num) == min_pay.end() || cost < min_pay[num]))
        {
            cout << num << ":" << cost << "," << entropy << endl;
            // cout << min_cost << endl;
            min_pay[num] = cost;
            if (num < N)
            {
                q.push({cost + A + lower(N, num * 2, A, B, C, D), {cost + A, num * 2}});
                q.push({cost + B + lower(N, num * 3, A, B, C, D), {cost + B, num * 3}});
                q.push({cost + C + lower(N, num * 5, A, B, C, D), {cost + C, num * 5}});
            }
            for (ll i = 1; num + i <= N + (i >> 1); i <<= 1)
            {
                // cout << i << endl;
                q.push({cost + i * D + lower(N, num + i, A, B, C, D), {cost + i * D, num + i}});
            }
            for (ll i = 1; num - i > 0; i <<= 1)
            {
                // cout << i << endl;
                q.push({cost + i * D + lower(N, num - i, A, B, C, D), {cost + i * D, num - i}});
            }

            if (num == N)
            {
                min_cost = min(min_cost, min_pay[N]);
                cout << min_cost << endl;
            }
        }
    }
    cout << min_pay[N] << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}