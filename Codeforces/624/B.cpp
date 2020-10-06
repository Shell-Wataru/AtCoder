#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    set<ll> ps;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        ll p;
        cin >> p;
        p--;
        ps.insert(p);
    }

    ll from = -10;
    ll to = -10;
    for (auto p:ps)
    {
        if (p == to){
            to = p + 1;
        }else{
            if (from != -10){
                // cout << "sort!!"  << from << "~" <<to << endl;
                sort(a.begin() + from, a.begin() + to + 1);
            }
            from = p;
            to = p + 1;
        }
    }
    if (from != -10){
        // cout << "sort!!"  << from << "~" <<to << endl;
        sort(a.begin() + from, a.begin() + to + 1);
    }


    // for (int i = 0; i < n; i++)
    // {
    //     cout << "," << a[i];
    // }
    // cout << endl;

    bool clear = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            clear = false;
            break;
        }
    }
    if (clear)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
