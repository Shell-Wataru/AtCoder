#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<set<ll>> G(n);
    vector<set<ll>> revG(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[b].insert(a);
        revG[a].insert(b);
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++)
    {
        if (G[i].empty())
        {
            q.push(i);
        }
    }
    vector<ll> ans;
    while (!q.empty())
    {
        ll current = q.top();
        q.pop();
        ans.push_back(current);
        for (auto to : revG[current])
        {
            G[to].erase(current);
            if (G[to].empty())
            {
                q.push(to);
            }
        }
    }
    if (ans.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << ans[i] + 1;
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
