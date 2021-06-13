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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<ll> shops(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            ll a;
            cin >> a;
            shops[i] += a * (1ll << j);
        }
        // cout << shops[i] << endl;
    }
    vector<vector<ll>> points(N, vector<ll>(11));
    for (int i = 0; i < N; i++)
    {
        for (size_t j = 0; j <= 10; j++)
        {
            cin >> points[i][j];
            // cout << points[i][j] << endl;
        }
    }
    ll max_p = numeric_limits<ll>::min();
    for (unsigned long long i = 1; i < (1ll << 10); i++)
    {
        ll p = 0;
        for (size_t j = 0; j < N; j++)
        {
            p += points[j][__builtin_popcount(i & shops[j])];
        }
        // if (p > max_p)
        // {
        //     cout << i << ":" << p << endl;
        //     cout << __popcount(i & shops[0]) << endl;
        //     cout << __popcount(i & shops[1]) << endl;
        //     cout << points[0][__popcount(i & shops[0])] << endl;
        //     cout << points[1][__popcount(i & shops[1])] << endl;

        // }
        max_p = max(p, max_p);
    }
    cout << max_p << endl;
    return 0;
}