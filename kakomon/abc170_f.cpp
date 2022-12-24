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

vector<pair<ll, ll>> directions = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

int main()
{
    // 整数の入力
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<vector<pair<ll, ll>>>> DP(H, vector<vector<pair<ll, ll>>>(W, vector<pair<ll, ll>>(4, {numeric_limits<ll>::max(), 0})));
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;
    vector<string> G(H);
    for (int i = 0; i < H; i++)
    {
        cin >> G[i];
    }
    deque<vector<ll>> q;
    deque<vector<ll>> next_q;
    for (int i = 0; i < 4; i++)
    {
        q.push_back({x1, y1, i, 1, -K});
    }
    while (!q.empty() || !next_q.empty())
    {
        if (q.empty()){
            swap(q,next_q);
            next_q.clear();
        }
        ll x = q.front()[0];
        ll y = q.front()[1];
        ll direction = q.front()[2];
        ll distance = q.front()[3];
        ll k = q.front()[4];
        q.pop_front();
        if (DP[x][y][direction] > make_pair(distance, k))
        {
            DP[x][y][direction] = {distance, k};
            for (int i = 0; i < 4; i++)
            {
                ll next_x = directions[i].first + x;
                ll next_y = directions[i].second + y;
                if (0 <= next_x && next_x < H && 0 <= next_y && next_y < W && G[next_x][next_y] == '.')
                {
                    if (i == direction && k < 0)
                    {
                        q.push_back({next_x, next_y, i, distance, k + 1});
                    }
                    else
                    {
                        next_q.push_back({next_x, next_y, i, distance + 1, -K+1});
                    }
                }
            }
        }
    }
    // for (int i = 0; i < H; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //     {
    //         ll m = numeric_limits<ll>::max();
    //         for (int k = 0; k < 4; k++)
    //         {
    //             m = min(m, DP[i][j][k].first);
    //         }
    //         if (G[i][j] == '@')
    //         {
    //             cout << '@';
    //         }
    //         else
    //         {
    //             cout << m;
    //         }
    //     }
    //     cout << endl;
    // }
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < 4; i++)
    {
        ans = min(ans, DP[x2][y2][i].first);
    }
    if (ans == numeric_limits<ll>::max()){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}