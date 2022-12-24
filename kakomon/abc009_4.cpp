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

vector<vector<ll>> matrix_multiply(vector<vector<ll>> &m1, vector<vector<ll>> &m2)
{
    ll n = m1.size();
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] ^= m1[i][k] & m2[k][j];
            }
        }
    }
    return ans;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> m, ll k)
{
    ll n = m.size();
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = (1ll << 32) - 1;
    }
    while (k > 0)
    {
        if (k & 1)
        {
            ans = matrix_multiply(m, ans);
        }
        m = matrix_multiply(m, m);
        k >>= 1;
    }
    return ans;
}
int solve()
{

    ll k, m;
    scanf("%lld", &k);
    scanf("%lld", &m);
    vector<ll> A(k);
    vector<ll> C(k);
    for (int i = 0; i < k; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> C[i];
    }
    vector<vector<ll>> matrix(k, vector<ll>(k, 0));
    for (int i = 0; i < k; i++)
    {
        matrix[k - 1][i] = C[k - 1 - i];
    }
    for (int i = 0; i < k-1; i++)
    {
        matrix[i][i + 1] = (1ll << 32) - 1;
    }
    // for(int i = 0;i < k;i++){
    //     for(int j = 0;j < k;j++){
    //         cout << matrix[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    if (m <= k)
    {
        cout << A[m - 1] << endl;
    }
    else
    {
        // cout << m - k << endl;
        vector<vector<ll>> result = matrix_power(matrix, m - k);
        // for(int i = 0;i < k;i++){
        //     for(int j = 0;j < k;j++){
        //         cout << result[i][j] << ",";
        //     }
        //     cout << endl;
        // }
        ll ans = 0;
        for (int i = 0; i < k; i++)
        {
            // cout << bitset<32>(result[k - 1][i] & A[i]) << endl;
            ans ^= result[k - 1][i] & A[i];
        }
        cout << ans << endl;
    }
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}