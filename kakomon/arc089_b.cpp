#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

ll sum(vector<vector<ll>> &ruiseki, ll xl, ll xr, ll yl, ll yr)
{
    return ruiseki[xr][yr] - ruiseki[xl][yr] - ruiseki[xr][yl] + ruiseki[xl][yl];
}

int solve()
{

    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> counts(k, vector<ll>(2 * k, 0));
    vector<vector<ll>> ruiseki(k + 1, vector<ll>(2 * k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'W')
        {
            y += k;
        }
        x %= 2 * k;
        y %= 2 * k;
        if (x >= k && y >= k)
        {
            counts[x - k][y - k]++;
        }
        else if (x >= k && y < k)
        {
            counts[x - k][y + k]++;
        }
        else if (x < k && y >= k)
        {
            counts[x][y]++;
        }
        else
        {
            counts[x][y]++;
        }
    }
    // for(int i = 0;i < k;i++){
    //     for(int j = 0;j < 2*k;j++){
    //         cout << counts[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 2 * k; j++)
        {
            ruiseki[i + 1][j + 1] = ruiseki[i + 1][j] + ruiseki[i][j + 1] - ruiseki[i][j] + counts[i][j];
        }
    }
    // cout << ruiseki[k][2*k] << endl;
    // cout << sum(ruiseki,0,k,0,2*k) << endl;
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ans = max(ans, sum(ruiseki, i, k, j, j + k) + sum(ruiseki, 0, i, 0, j) + sum(ruiseki, 0, i, j + k, 2 * k));
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ans = max(ans, sum(ruiseki, 0, i, j, j + k) + sum(ruiseki, i, k, 0, j) + sum(ruiseki, i, k, j + k, 2 * k));
        }
    }
    cout << ans << endl;
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
    return 0;
}