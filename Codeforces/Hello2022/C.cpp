#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

ll query(ll i)
{
    cout << "? " << i + 1 << endl;
    cout << flush;
    ll ret;
    cin >> ret;
    return ret - 1;
}

int solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n, -1);
    ll query_count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (p[i] != -1)
        {
            continue;
        }
        vector<ll> seq;
        while (true)
        {
            ll ret = query(i);
            query_count++;
            if (seq.empty() || seq[0] != ret)
            {
                seq.push_back(ret);
            }
            else
            {
                break;
            }
        }
        ll last = i;
        ll period = seq.size();
        for (ll j = 0; j < period; j++)
        {
            p[last] = seq[(j + 1 + period - ((query_count - 1) % period)) % period];
            last = seq[(j + 1 + period - ((query_count - 1) % period)) % period];
        }
    }
    cout << "!";
    for (ll i = 0; i < n; i++)
    {
        cout << " " << p[i] + 1;
    }
    cout << endl;
    cout << flush;
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
    // cout << flush;
    return 0;
}
