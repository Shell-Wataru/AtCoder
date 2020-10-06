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

int solve()
{
    // cout << "==" << endl;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> G(n,vector<ll>(m));
    for(int i = 0;i < n;i++){
        for (size_t j = 0; j < m; j++)
        {
            scanf("%lld",&G[i][j]);
        }
    }
    ll ans = 0;
    // ll center_x = n/2;
    // ll center_y = m/2;
    for(int i = 0;i < (n + m - 1)/2;i++){
        ll ones = 0;
        ll zeros = 0;
        for (size_t j = 0; j < m; j++)
        {
            ll x = j;
            ll y = i - j;
            if (0 <= y && y < n && 0 <= x && x < m){
                // cout << y << ","<< x << endl;

                if (G[y][x] == 0){
                    zeros++;
                }else{
                    ones++;
                }
            }
        }

        for (size_t j = 0; j < m; j++)
        {
            ll x = j;
            ll y = n + m - 2 - i - j;
            if (0 <= y && y < n && 0 <= x && x < m){
            // cout << y << ","<< x << endl;
                if (G[y][x] == 0){
                    zeros++;
                }else{
                    ones++;
                }
            }
        }
        // cout << i << ":" << ones << "," << zeros << endl;
        ans += min(ones,zeros);
    }
    cout << ans << endl;
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
