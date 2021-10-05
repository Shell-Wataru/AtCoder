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
    ll R, C, K;
    cin >> R >> C >> K;
    vector<string> G(R);
    for (int i = 0; i < R; i++)
    {
        cin >> G[i];
    }
    vector<vector<ll>> RuisekiWa(R + C + 1, vector<ll>(R + C + 1, 0));
    ll origin_i = 1;
    ll origin_j = R;
    for (int i = 1; i <= R + C; i++)
    {
        for (int j = 1; j <= R + C; j++)
        {
            RuisekiWa[i][j] = RuisekiWa[i][j - 1] + RuisekiWa[i - 1][j] - RuisekiWa[i - 1][j - 1];
            ll diff_i = i - origin_i;
            ll diff_j = j - origin_j;
            if ((diff_i + diff_j) % 2 == 0)
            {
                ll x = (diff_i - diff_j) / 2;
                ll y = (diff_i + diff_j) / 2;
                if (0 <= x && x < R && 0 <= y && y < C && G[x][y] == 'x')
                {
                    RuisekiWa[i][j] += 1;
                }
            }
        }
    }
    // for (int i = 1; i <= R + C; i++)
    // {
    //     for (int j = 1; j <= R + C; j++)
    //     {
    //         cout << RuisekiWa[i][j] - RuisekiWa[i - 1][j] - RuisekiWa[i][j - 1] + RuisekiWa[i - 1][j - 1] << ",";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for (int x = K - 1; x < R - (K - 1); x++)
    {
        for (int y = K - 1; y < C - (K - 1); y++)
        {
            ll i = origin_i + x + y;
            ll j = origin_j - x + y;
            ll total = RuisekiWa[i + (K - 1)][j + (K - 1)] - RuisekiWa[i - (K - 1) - 1][j + (K - 1)] - RuisekiWa[i + (K - 1)][j - (K - 1) - 1] + RuisekiWa[i - (K - 1) - 1][j - (K - 1) - 1];
            // cout << x << "," << y << ":" << total << endl;
            if (total == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}