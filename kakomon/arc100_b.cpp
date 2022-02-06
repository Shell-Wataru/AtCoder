#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <stack>

using namespace std;
using ll = long long;

ll value(vector<ll> &sumA, ll left, ll right, ll center)
{
    return abs(sumA[center] - sumA[left] - sumA[right] + sumA[center]);
}

ll three_search(vector<ll> &sumA, ll left, ll right, ll l, ll r)
{
    // cout << l << "~" << r << endl;
    if (l + 2 >= r)
    {
        vector<pair<ll, ll>> values;
        for (int i = l; i < r; i++)
        {
            values.push_back({value(sumA, left, right, i), i});
        }
        sort(values.begin(), values.end());
        return values.front().second;
    }
    else
    {
        ll t1 = (2 * l + r) / 3;
        ll t2 = (l + 2 * r) / 3;
        ll t1_value = value(sumA, left, right, t1);
        ll t2_value = value(sumA, left, right, t2);
        if (t1_value <= t2_value)
        {
            return three_search(sumA, left, right, l, t2);
        }
        else
        {
            return three_search(sumA, left, right, t1, r);
        }
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> sumA(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        sumA[i + 1] += sumA[i] + A[i];
    }
    ll ans = numeric_limits<ll>::max();
    for (int b = 2; b < N-1; b++)
    {
        ll a = three_search(sumA,0,b,0,b);
        ll c = three_search(sumA,b,N,b,N);
        ll max_v = sumA[a] - sumA[0];
        // cout << "a:" << a << ",b:" << b << ",c:" << c << endl;
        max_v = max(max_v,sumA[b] - sumA[a]);
        max_v = max(max_v,sumA[c] - sumA[b]);
        max_v = max(max_v,sumA[N] - sumA[c]);
        ll min_v = sumA[a] - sumA[0];
        min_v = min(min_v,sumA[b] - sumA[a]);
        min_v = min(min_v,sumA[c] - sumA[b]);
        min_v = min(min_v,sumA[N] - sumA[c]);
        // cout << max_v << endl;
        // cout << min_v << endl;
        ans = min(ans,max_v - min_v);
    }
    cout << ans << endl;
    return 0;
}
