#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int solve()
{
    ll H, W;
    scanf("%lld", &H);
    scanf("%lld", &W);
    ll rs, cs;
    ll rg, cg;
    cin >> rs >> cs;
    cin >> rg >> cg;
    rs--;
    cs--;
    rg--;
    cg--;
    vector<vector<vector<ll>>> Distances(4,vector<vector<ll>>(H, vector<ll>(W, numeric_limits<ll>::max())));
    queue<vector<ll>> q;
    vector<string> G(H);
    for (int i = 0; i < H; i++)
    {
        cin >> G[i];
    }
    q.push({0,rs, cs});
    q.push({1,rs, cs});
    q.push({2,rs, cs});
    q.push({3,rs, cs});
    Distances[0][rs][cs] = 0;
    Distances[1][rs][cs] = 0;
    Distances[2][rs][cs] = 0;
    Distances[3][rs][cs] = 0;
    vector<pair<ll, ll>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};
    while (!q.empty())
    {
        ll d_index = q.front()[0];
        ll r = q.front()[1];
        ll c = q.front()[2];
        q.pop();
        for(int j = 0;j < 4;j++)
        {
            auto d = directions[j];
            for (int i = 1; i < max(H, W); i++)
            {
                ll next_r = r + d.first * i;
                ll next_c = c + d.second * i;
                if (0 <= next_r && next_r < H && 0 <= next_c && next_c < W && G[next_r][next_c] == '.' && Distances[j][next_r][next_c] == numeric_limits<ll>::max())
                {
                    Distances[j][next_r][next_c] = Distances[d_index][r][c] + 1;
                    q.push({j,next_r, next_c});
                }
                else
                {
                    break;
                }
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < 4;i++){
        ans = min(ans,Distances[i][rg][cg]);
    }
    cout << ans - 1 << endl;
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}