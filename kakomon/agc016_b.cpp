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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    map<ll, ll> counts;

    ll min_colors = numeric_limits<ll>::max();
    ll max_colors = numeric_limits<ll>::min();
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        min_colors = min(min_colors, a);
        max_colors = max(max_colors, a);
        counts[a]++;
    }
    if (counts.size() > 2)
    {
        cout << "No" << endl;
    }
    else if (counts.size() == 2)
    {
        if (min_colors + 1 != max_colors)
        {
            cout << "No" << endl;
            return 0;
        }

        ll m = counts[min_colors];
        ll M = counts[max_colors];
        // cout << m << endl;
        // cout << M << endl;
        if (max_colors <= m + M / 2 && m <= min_colors)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        if (min_colors == N - 1)
        {
            cout << "Yes" << endl;
        }
        else if (2 * min_colors <= N)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}