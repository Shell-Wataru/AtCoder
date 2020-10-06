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

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n, k, z;
    cin >> n >> k >> z;
    vector<ll> A(n);
    vector<ll> sumA(n + 1, 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
        sumA[i + 1] = sumA[i] + A[i];
    }
    ll max_score = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= z && i - 1 <= k - 2 * j; j++)
        {
            max_score = max(max_score, sumA[k - 2 * j + 1] + j * (A[i - 1] + A[i]));
        }
    }
    cout << max_score << endl;
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
