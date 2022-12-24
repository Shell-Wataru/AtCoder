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
using namespace std;
using ll = long long;

int solve()
{
    string S;
    ll K;
    cin >> S;
    scanf("%lld", &K);
    ll n = S.size();
    vector<vector<vector<ll>>> DP(n+1, vector<vector<ll>>(n + 1, vector<ll>(K + 1,0)));
    for (int i = 0; i < n; i++)
    {
        DP[i][i + 1][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; i + j < n; j++)
        {
            if (S[j] == S[j + i])
            {
                for (int k = 0; k <= K; k++)
                {
                    DP[j][i + j + 1][k] = max(DP[j][i + j + 1][k], DP[j + 1][i + j+1][k]);
                    DP[j][i + j + 1][k] = max(DP[j][i + j + 1][k], DP[j][i + j][k]);
                    DP[j][i + j + 1][k] = max(DP[j][i + j + 1][k], DP[j + 1][i + j][k] + 2);
                }
            }
            else
            {
                for (int k = 0; k <= K; k++)
                {
                    DP[j][i + j + 1][k] = max(DP[j][i + j + 1][k], DP[j + 1][i + j+1][k]);
                    DP[j][i + j + 1][k] = max(DP[j][i + j + 1][k], DP[j][i + j][k]);
                }
                for (int k = 0; k < K; k++)
                {
                    DP[j][i + j + 1][k+1] = max(DP[j][i + j + 1][k+1], DP[j + 1][i + j][k]+2);
                }
            }
        }
    }

    // for(int k = 0;k <= K;k++){
    //     for(int i = 0;i < n;i++){
    //         for(int j = 0;j <= n;j++){
    //             cout << DP[i][j][k] << ",";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for(int i = 0;i <= K;i++){
        ans = max(ans,DP[0][n][i]);
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
