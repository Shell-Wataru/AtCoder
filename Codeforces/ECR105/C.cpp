#define _USE_MATH_DEFINES
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
ll BASE_NUM = 1000000007;
int sub_solve(vector<ll> &a, vector<ll> &b)
{
    ll n = a.size();
    ll m = b.size();
    vector<ll> matches(m, 0);
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j < n)
        {
            if (a[j] == b[i])
            {
                matches[i] = 1;
            }
            else if (a[j] > b[i])
            {
                break;
            }
            j++;
        }
    }

    for (int i = m - 2; i >= 0; i--)
    {
        matches[i] += matches[i + 1];
    }

    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ll blocks = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll holes = (i + 1) - (upper_bound(b.begin(), b.end(), b[i] - blocks) - b.begin());
        // cout << blocks << " " << holes << endl;
        if (i != m - 1)
        {
            ans = max(ans, holes + matches[i + 1]);
        }else{
            ans = max(ans, holes);
        }
    }
    return ans;
}
int solve()
{
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<ll> positive_a;
    vector<ll> positive_b;
    vector<ll> negative_a;
    vector<ll> negative_b;
    for (int i = 0; i < n; i++)
    {
        ll a;
        scanf("%lld", &a);
        if (a > 0)
        {
            positive_a.push_back(a);
        }
        else
        {
            negative_a.push_back(-a);
        }
    }

    for (int i = 0; i < m; i++)
    {
        ll b;
        scanf("%lld", &b);
        if (b > 0)
        {
            positive_b.push_back(b);
        }
        else
        {
            negative_b.push_back(-b);
        }
    }
    sort(positive_a.begin(), positive_a.end());
    sort(positive_b.begin(), positive_b.end());
    sort(negative_a.begin(), negative_a.end());
    sort(negative_b.begin(), negative_b.end());
    cout << sub_solve(positive_a, positive_b) + sub_solve(negative_a, negative_b) << "\n";
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
