#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

bool paintable(ll i, ll j, vector<vector<ll>> &colors)
{
    ll zero_count = 0;
    ll non_zero_count = 0;
    ll non_zero = 0;

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (colors[i + x][j + y] == 0)
            {
                zero_count++;
            }
            else if (non_zero == 0 || colors[i + x][j + y] == non_zero)
            {
                non_zero = colors[i + x][j + y];
                non_zero_count++;
            }
            else
            {
                continue;
            }
        }
    }
    return non_zero_count + zero_count == 4 && zero_count != 4;
}

vector<pair<ll, ll>> directions = {
    {1, 1},
    {1, 0},
    {1, -1},
    {0, 1},
    {0, 0},
    {0, -1},
    {-1, 1},
    {-1, 0},
    {-1, 1}};
int dfs(ll n,ll m,ll i,ll j,vector<vector<ll>> &colors,vector<vector<ll>> &answer){
    ll non_zero = 0;
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (colors[i + x][j + y] != 0)
            {
                non_zero = colors[i + x][j + y];
            }
            colors[i + x][j + y] = 0;
        }
    }
    if (non_zero != 0)
    {
        answer.push_back({i, j, non_zero});
    }
    for (auto d : directions)
    {
        ll x = i + d.first;
        ll y = j + d.second;
        if (0 <= x && x < n - 1 && 0 <= y && y < m - 1 && paintable(x, y, colors))
        {
            dfs(n,m,x,y,colors,answer);
        }
    }
    return 0;
}
int solve()
{
    ll n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<ll>> colors(n, vector<ll>(m));
    vector<vector<ll>> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &colors[i][j]);
        }
    }
    // cout << "!!" << endl;
    queue<pair<ll, ll>> q;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (paintable(i, j, colors))
            {
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        // cout << q.size() << endl;
        ll i = q.front().first;
        ll j = q.front().second;
        q.pop();
        dfs(n,m,i,j,colors,answer);
    }
    // cout << "!!" << endl;
    bool is_ok = true;
    for (auto row : colors)
    {
        for (auto cell : row)
        {
            if (cell != 0)
            {
                is_ok = false;
                break;
            }
        }
    }
    if (is_ok)
    {
        reverse(answer.begin(), answer.end());
        cout << answer.size() << endl;
        for (auto a : answer)
        {
            cout << a[0] + 1 << " " << a[1] + 1 << " " << a[2] << "\n";
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}

int main()
{
    // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}
