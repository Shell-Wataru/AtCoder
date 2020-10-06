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

bool is_clear(ll n, set<ll> &a, set<ll> &b)
{
    if (n != (a.size() + b.size()))
    {
        return false;
    }
    for (int i = 1; i <= a.size(); i++)
    {
        if (a.find(i) == a.end())
        {
            return false;
        }
    }

    for (int i = 1; i <= b.size(); i++)
    {
        if (b.find(i) == b.end())
        {
            return false;
        }
    }

    return true;
}
int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    set<ll> a, b, c, d;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        // cout << "a" << A[i] << endl;
        if (a.find(A[i]) == a.end())
        {
            a.insert(A[i]);
        }
        else
        {
            break;
        }
    }

    for (; i < n; i++)
    {
        // cout << "b" << A[i] << endl;
        if (b.find(A[i]) == b.end())
        {
            b.insert(A[i]);
        }
        else
        {
            break;
        }
    }
    reverse(A.begin(), A.end());
    i = 0;
    for (i = 0; i < n; i++)
    {
        // cout << "d" << A[i] << endl;
        if (d.find(A[i]) == d.end())
        {
            d.insert(A[i]);
        }
        else
        {
            break;
        }
    }

    for (; i < n; i++)
    {
        // cout << "c" << A[i] << endl;
        if (c.find(A[i]) == c.end())
        {
            c.insert(A[i]);
        }
        else
        {
            break;
        }
    }

    ll patterns = 0;
    if (is_clear(n, a, b))
    {
        // cout << "patten1" << endl;
        patterns++;
    }
    if (is_clear(n, c, d) && a.size() != c.size())
    {
        // cout << "patten2" << endl;
        patterns++;
    }

    cout << patterns << endl;
    if (is_clear(n, a, b))
    {
        cout << a.size() << " " << b.size() << endl;
    }
    if (is_clear(n, c, d) && a.size() != c.size())
    {
        cout << c.size() << " " << d.size() << endl;
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
