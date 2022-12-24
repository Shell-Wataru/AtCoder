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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(m);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a;
        cin >> b;
        a--;
        b--;
        G[a].push_back(i);
        G[b].push_back(i);
    }
    ll clear_count = 0;
    vector<ll> counts(n, 0);
    vector<ll> ans(m + 2, 0);
    ll l = 0;
    ll r = 0;
    while (l < m)
    {
        while (clear_count < n && r < m)
        {
            for (auto to : G[r])
            {
                counts[to]++;
                if (counts[to] == 1)
                {
                    clear_count++;
                }
            }
            r++;
        }
        if (clear_count < n)
        {
            break;
        }
        // cout << l << "~" << r << endl;
        ans[r - l]++;
        ans[m - l + 1]--;
        for (auto to : G[l])
        {
            counts[to]--;
            if (counts[to] == 0)
            {
                clear_count--;
            }
        }
        l++;
    }
    // cout << "!!" << endl;
    for (int i = 1; i <= m; i++)
    {
        ans[i] += ans[i - 1];
        if (i != 1)
        {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << "\n";
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