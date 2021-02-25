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

vector<pair<ll, ll>> sub_solve(ll n, map<ll, ll> counts, ll x)
{
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        auto end_ptr = counts.end();
        end_ptr--;
        ll bigger = end_ptr->first;
        counts[bigger]--;
        if (counts[bigger] == 0)
        {
            counts.erase(bigger);
        }
        // cout << bigger << "\n";
        if (counts.find(x - bigger) == counts.end())
        {
            return ans;
        }
        else
        {
            ans.push_back({bigger, x - bigger});

            counts[x - bigger]--;
            if (counts[x - bigger] == 0)
            {
                counts.erase(x - bigger);
            }
            x = bigger;
        }
    }
    return ans;
}
int solve()
{
    ll n;
    cin >> n;
    vector<ll> a(2 * n);
    map<ll, ll> counts;
    for (size_t i = 0; i < 2 * n; i++)
    {
        scanf("%lld", &a[i]);
        counts[a[i]] += 1;
    }
    sort(a.begin(), a.end());
    ll first = a.back();
    a.pop_back();
    counts[first]--;
    if (counts[first] == 0)
    {
        counts.erase(first);
    }
    a.pop_back();
    for (int i = 0; i < 2 * n - 1; i++)
    {
        counts[a[i]]--;
        if (counts[a[i]] == 0)
        {
            counts.erase(a[i]);
        }
        vector<pair<ll, ll>> ans = sub_solve(n, counts, first);
        counts[a[i]]++;
        // cout << ans.size() << "\n";
        if (ans.size() == n - 1)
        {
            cout << "YES"
                 << "\n";
            cout << first + a[i] << "\n";
            cout << first << " " << a[i] << "\n";
            for (auto &p : ans)
            {
                cout << p.first << " " << p.second << "\n";
            }
            return 0;
        }
    }
    cout << "NO"
         << "\n";
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
