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

    ll n, a,b;
    scanf("%lld", &n);
    scanf("%lld", &a);
    scanf("%lld", &b);
    if (a +b - 1 <= n && n <= a*b){
        ll current = 0;
        for(int i = 1;i <= a;i++){
            ll take = min(n-current-(a-i),b);
            current += take;
            for(int j = 0;j < take;j++){
                if (i != 1 || j != 0){
                    cout << " ";
                }
                cout << current - j;
            }
        }
        cout << endl;
    }else{
        cout << -1  << endl;
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