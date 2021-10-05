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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

ll times(vector<pair<ll, ll>> &lr, ll s, ll t)
{
    for (int i = 0; i < lr.size(); i++)
    {
        ll l = lr[i].first;
        ll r = lr[i].second;
        // cout << s << " " << t << endl;
        if (l <= s && s <= r && l <= t && t <= r)
        {
            return i + 1;
        }
        else if (l <= s && s <= r)
        {
            if (t > r)
            {
                s = r;
            }
            else
            {
                s = l;
            }
        }
    }
    return numeric_limits<ll>::max();
}
int main()
{
    // 整数の入力
    ll N, D, K;
    cin >> N >> D >> K;
    vector<pair<ll, ll>> lr(D);
    for (int i = 0; i < D; i++)
    {
        cin >> lr[i].first;
        cin >> lr[i].second;
    }

    for (int i = 0; i < K; i++)
    {
        ll s, t;
        cin >> s >> t;
        cout << times(lr, s, t) << endl;
    }
    return 0;
}