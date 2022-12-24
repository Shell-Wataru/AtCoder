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

int query(ll i, ll j, ll k)
{
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    ll ret;
    cin >> ret;
    return ret;
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    ll maximum1 = -1;
    ll maximum1_index = -1;
    for (int i = 2; i < n; i++)
    {
        ll ret = query(0, 1, i);
        if (ret >= maximum1)
        {
            maximum1 = ret;
            maximum1_index = i;
        }
    }
    ll maximum2 = -1;
    ll maximum2_index = -1;
    for (int i = 1; i < n; i++)
    {
        if (i == maximum1_index)
        {
            continue;
        }
        ll ret = query(0, i, maximum1_index);
        if (ret >= maximum2)
        {
            maximum2 = ret;
            maximum2_index = i;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (i != maximum1_index && i != maximum2_index)
        {
            ll ret1 = query(maximum1_index, maximum2_index, i);
            ll ret2 = query(0, maximum2_index, i);
            // cerr << ret << endl;
            if (ret1 == maximum2)
            {
                cout << "! " << maximum1_index + 1 << " " << maximum2_index + 1 << endl;
            }
            else if (ret2 == maximum2)
            {
                cout << "! " << 1 << " " << maximum2_index + 1 << endl;
            }
            else
            {
                cout << "! " << 1 << " " << maximum1_index + 1 << endl;
            }
            break;
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
