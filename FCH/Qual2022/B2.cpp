#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve()
{
    ll R, C;
    cin >> R >> C;
    vector<string> G(R);
    for (int i = 0; i < R; i++)
    {
        cin >> G[i];
    }
    vector<string> canputG(R, string(C, '^'));
    vector<vector<ll>> canputNeighbors(R, vector<ll>(C, 0));
    queue<pair<ll, ll>> q;
    vector<pair<ll, ll>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (G[i][j] == '#')
            {
                canputG[i][j] = '#';
                continue;
            }
            ll can_put_neighbors = 0;
            for (auto d : directions)
            {
                ll next_i = i + d.first;
                ll next_j = j + d.second;
                if (0 <= next_i && next_i < R && 0 <= next_j && next_j < C)
                {
                    if (G[next_i][next_j] != '#')
                    {
                        can_put_neighbors++;
                    }
                }
            }
            canputNeighbors[i][j] = can_put_neighbors;
            if (can_put_neighbors <= 1)
            {
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        ll i = q.front().first;
        ll j = q.front().second;
        q.pop();
        canputG[i][j] = '#';
        for (auto d : directions)
        {
            ll next_i = i + d.first;
            ll next_j = j + d.second;
            if (0 <= next_i && next_i < R && 0 <= next_j && next_j < C)
            {
                if (canputG[next_i][next_j] != '#')
                {
                    canputNeighbors[next_i][next_j]--;
                    if (canputNeighbors[next_i][next_j] <= 1)
                    {
                        q.push({next_i, next_j});
                    }
                }
            }
        }
    }
    bool can_make = true;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (canputG[i][j] == '#' && G[i][j] == '^')
            {

                can_make = false;
                break;
            }else if (canputG[i][j] == '^' && G[i][j] == '.'){
                G[i][j] = '^';
            }
        }
    }
    if (can_make)
    {
        string ans;
        ans += "Possible\n";
        for (int i = 0; i < R; i++)
        {
            ans += G[i] + "\n";
        }
        return ans;
    }
    else
    {
        return "Impossible\n";
    }
}

int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans;
    }
    cout << flush;
    return 0;
}