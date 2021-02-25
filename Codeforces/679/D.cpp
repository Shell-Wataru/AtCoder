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
const ll BASE_NUM = 1000000007;

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int solve()
{
    ll x, y;
    scanf("%lld", &x);
    scanf("%lld", &y);
    vector<vector<ll>> G(7, vector<ll>(7, numeric_limits<ll>::max() / 2));
    vector<ll> c(6);
    for (size_t i = 0; i < 6; i++)
    {
        scanf("%lld", &c[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        G[i][i] = 0;
    }
    G[0][1] = c[0];
    G[5][6] = c[0];
    G[3][2] = c[0];
    G[4][0] = c[0];
    G[0][2] = c[1];
    G[6][1] = c[1];
    G[5][0] = c[1];
    G[4][3] = c[1];
    G[0][3] = c[2];
    G[1][2] = c[2];
    G[5][4] = c[2];
    G[6][0] = c[2];
    G[0][4] = c[3];
    G[2][3] = c[3];
    G[6][5] = c[3];
    G[1][0] = c[3];
    G[0][5] = c[4];
    G[3][4] = c[4];
    G[1][6] = c[4];
    G[2][0] = c[4];
    G[0][6] = c[5];
    G[2][1] = c[5];
    G[4][5] = c[5];
    G[3][0] = c[5];
    warshall_floyd(7, G);
    // for (size_t i = 0; i < 7; i++)
    // {
    //     for (size_t j = 0; j < 7; j++)
    //     {
    //         cout << G[i][j] << ",";
    //     }
    //     cout << endl;
    // }

    if (x >= 0 && y >= 0)
    {
        if (x >= y)
        {
            ll c6_count = x - y;
            ll c1_count = y;
            cout << c1_count * G[0][1] + c6_count * G[0][6] << endl;
        }
        else
        {
            ll c1_count = x;
            ll c2_count = y - x;
            cout << c1_count * G[0][1] + c2_count * G[0][2] << endl;
        }
    }
    else if (x >= 0 && y < 0)
    {
        ll c6_count = x;
        ll c5_count = -y;
        cout << c5_count * G[0][5] + c6_count * G[0][6] << endl;
    }
    else if (x < 0 && y >= 0)
    {
        ll c2_count = y;
        ll c3_count = -x;
        cout << c2_count * G[0][2] + c3_count * G[0][3] << endl;
    }
    else if (x < 0 && y < 0)
    {
        if (x <= y)
        {
            ll c3_count = -x + y;
            ll c4_count = -y;
            cout << c3_count * G[0][3] + c4_count * G[0][4] << endl;
        }
        else
        {
            ll c4_count = -x;
            ll c5_count = -y + x;
            cout << c4_count * G[0][4] + c5_count * G[0][5] << endl;
        }
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
