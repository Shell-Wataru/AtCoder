#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

vector<ll> base(ll M, ll d)
{
    vector<ll> ans;
    while (M > 0)
    {
        ans.push_back(M % d);
        M /= d;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool is_greater(vector<ll> &a, vector<ll> &b)
{
    if (a.size() == b.size())
    {
        return a > b;
    }
    else
    {
        return a.size() > b.size();
    }
}

ll max_d(vector<ll> &X, ll M, ll l, ll r)
{
    // cout << l <<" " << r << endl;
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    vector<ll> m = base(M, center);
    if (is_greater(X, m))
    {
        return max_d(X, M, l, center);
    }
    else
    {
        return max_d(X, M, center, r);
    }
}

int main()
{
    // 整数の入力
    string X;
    ll M;
    cin >> X;
    cin >> M;
    vector<ll> x;
    ll d = 0;
    for (auto c : X)
    {
        x.push_back(c - '0');
        d = max(d, (ll)(c - '0'));
    }
    vector<ll> m_min_d = base(M, d + 1);
    // cout << d << endl;
    if (is_greater(x, m_min_d))
    {
        cout << 0 << endl;
    }
    else if (X.size() == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << max_d(x, M, d + 1, numeric_limits<ll>::max() / 2) - d << endl;
    }

    return 0;
}