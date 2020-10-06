#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

struct compass_neighbor
{
    ll x, y, value;
};

string solve()
{
    ll R, C;
    cin >> R >> C;
    vector<vector<ll>> S(R, vector<ll>(C, -1));
    vector<vector<vector<compass_neighbor>>> Neighbors(R, vector<vector<compass_neighbor>>(C, vector<compass_neighbor>(4, {-1, -1, -1})));
    vector<pair<ll, ll>> directions = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> S[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                ll x = i + directions[d].first;
                ll y = j + directions[d].second;
                if (0 <= x && x < R && 0 <= y && y <= C)
                {
                    Neighbors[i][j][d] = {x, y, S[x][y]};
                }
            }
        }
    }
    ll changes = -1;
    ll total_sum = 0;
    while (changes != 0)
    {
        changes = 0;
        vector<pair<ll, ll>> losers;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (S[i][j] != -1){
                    total_sum += S[i][j];
                    ll n_sum = 0;
                    ll n_count = 0;
                    for (int d = 0; d < 4; d++)
                    {
                        if (Neighbors[i][j][d].value != -1){
                            n_sum += Neighbors[i][j][d].value;
                            n_count++;
                        }
                    }
                    if (S[i][j] * n_count < n_sum ){
                        losers.push_back({i,j});
                        changes++;
                    }
                }
            }
        }

        for(auto p:losers){
            for (int d = 0; d < 4; d++)
            {
                if (Neighbors[p.first][p.second][d].value != -1){
                    ll x = Neighbors[p.first][p.second][d].x;
                    ll y = Neighbors[p.first][p.second][d].y;
                    Neighbors[x][y][(d + 2) % 4]= Neighbors[p.first][p.second][(d + 2) % 4];
                }
            }
            S[p.first][p.second] = -1;
        }
    }
    return to_string(total_sum);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}