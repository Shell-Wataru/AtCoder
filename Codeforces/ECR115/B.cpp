#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<vector<ll>> students(n, vector<ll>(5));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%lld", &students[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            ll i_count = 0;
            ll j_count = 0;
            ll both_count = 0;
            for (int k = 0; k < n; k++)
            {
                if (students[k][i] && students[k][j])
                {
                    both_count++;
                }
                else if (students[k][i])
                {
                    i_count++;
                }
                else if (students[k][j])
                {
                    j_count++;
                }
            }
            if (both_count + i_count + j_count >= n && i_count <= n / 2 && j_count <= n / 2)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
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
    cout << flush;
    return 0;
}
