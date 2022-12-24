#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
    ll s, t, m;
    scanf("%lld", &s);
    scanf("%lld", &t);
    scanf("%lld", &m);

    vector<vector<ll>> G(s);
    // cout << "!" << endl;
    for (int i = 0; i < m; i++)
    {
        // cout << i << m << endl;
        ll u, v;
        scanf("%lld", &u);
        scanf("%lld", &v);
        u--;
        v--;
        G[u].push_back(v - s);
    }

    // cout << "!" << endl;
    vector<vector<ll>> DP(t, vector<ll>(t, -1));
    for (int i = 0; i < s; i++)
    {
        sort(G[i].begin(), G[i].end());
        for (int j = 0; j < G[i].size(); j++)
        {
            for (int k = j + 1; k < G[i].size(); k++)
            {
                if (DP[G[i][j]][G[i][k]] == -1)
                {
                    DP[G[i][j]][G[i][k]] = i;
                }
                else
                {
                    cout << i + 1 << " " << DP[G[i][j]][G[i][k]] + 1 << " " << G[i][j] + 1 + s << " " << G[i][k] + 1+s << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}