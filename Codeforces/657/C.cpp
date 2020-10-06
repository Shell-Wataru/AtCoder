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

int solve()
{
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<pair<ll, ll>> AB(m);
    ll max_b = -1;
    for (size_t i = 0; i < m; i++)
    {
        scanf("%lld", &AB[i].first);
        scanf("%lld", &AB[i].second);
    }
    sort(AB.begin(), AB.end(), greater<pair<ll, ll>>());
    vector<ll> A(m, 0);
    for (size_t i = 0; i < m; i++)
    {
        A[i] = AB[i].first;
    }

    vector<ll> sumA(m+1, 0);
    for (size_t i = 0; i < m; i++)
    {
        sumA[i+1] = sumA[i] + A[i];
    }
    ll max_happiness = 0;
    for (int i = 0; i < m; i++)
    {
        ll index = lower_bound(A.begin(), A.end(), AB[i].second, greater<ll>()) - A.begin();

        ll happiness;
        if (i < index)
        {
            if (index >= n)
            {
                happiness = sumA[n];
            }
            else
            {
                happiness = sumA[index] + AB[i].second * (n - index);
            }
        }
        else
        {
            if (index + 1 >= n)
            {
                happiness = sumA[n - 1] + AB[i].first;
            }
            else
            {
                happiness = sumA[index] + AB[i].first + AB[i].second * (n - index - 1);
            }
        }
        // cout << "i" << i << "index" << index << "h" << happiness << endl;
        max_happiness = max(max_happiness, happiness);
    }
    cout << max_happiness << endl;
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
