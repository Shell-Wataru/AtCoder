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
#include <set>
using namespace std;
using ll = long long;

ll solve()
{
    ll H, W;
    cin >> H >> W;
    vector<string> G(H);
    for (int i = 0; i < H; i++)
    {
        cin >> G[i];
    }
    vector<vector<vector<bool>>> DP(H * W, vector<vector<bool>>(H * W, vector<bool>(1ll << (H * W))));
    for (int i = 0; i < H * W; i++)
    {
        ll x = i / W;
        ll y = i % W;
        if (G[x][y] == '.')
        {
            DP[i][i][0] = true;
        }
    }
    vector<pair<ll, ll>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};
    for (int i = 0; i < H * W; i++)
    {

        for (int k = 0; k < 1ll << (H * W); k++)
        {
            for (int j = 0; j < H * W; j++)
            {
                ll x = j / W;
                ll y = j % W;
                if (DP[i][j][k])
                {
                    for (auto &d : directions)
                    {
                        ll next_x = x + d.first;
                        ll next_y = y + d.second;
                        ll next_j = next_x * W + next_y;
                        if (0 <= next_x && next_x < H &&
                            0 <= next_y && next_y < W &&
                            G[next_x][next_y] == '.' &&
                            !(k & 1ll << next_j))
                        {
                            // cout << i << "," << next_j << ":" << (k | 1ll << next_j) << "," << __builtin_popcountll(k | 1ll << next_j) << endl;
                            DP[i][next_j][k | 1ll << next_j] = true;
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < H * W; i++)
    {
        for (int k = 0; k < 1ll << (H * W); k++)
        {
            if (DP[i][i][k] && __builtin_popcountll(k) >= 3)
            {
                ans = max(ans, __builtin_popcountll(k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
