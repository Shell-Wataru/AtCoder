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
#include <set>
using namespace std;
using ll = long long;

ll solve()
{
    ll N, K, M;
    cin >> N >> K >> M;
    ll MAX_SUM = N* (N-1)/2 * K;
    vector<vector<ll>> DP(N, vector<ll>(MAX_SUM + 1, 0));
    // cout << MAX_SUM << endl;
    DP[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        vector<vector<ll>> ruiseki(i, vector<ll>(1, 0));
        // cout << i << ":" << endl;
        for (int j = 0; j <= MAX_SUM; j++)
        {
            ruiseki[j % i].push_back(ruiseki[j % i].back() + DP[i - 1][j]);
            ruiseki[j % i].back() %= M;
            // cout << ruiseki[j % i].back() << endl;
        }
        for (int j = 0; j <= MAX_SUM; j++)
        {
            DP[i][j] = ruiseki[j%i][j/i + 1] - ruiseki[j%i][max(j/i - K,0ll)];
            DP[i][j] += M;
            DP[i][j] %= M;
        }
    }

    for(int i = 0;i < N;i++){
        ll ans = 0;
        for(int j = 0;j <= MAX_SUM;j++){
            if (j == 0){
                ll temp = DP[i][j] * DP[N-1-i][j] % M;
                temp = temp * K % M;
                ans += temp;
                ans %= M;
            }else{
                ll temp = DP[i][j] * DP[N-1-i][j] % M;
                temp = temp * (K+1) % M;
                ans += temp;
                ans %= M;
            }
        }
        cout << ans << "\n";
    }

    // for(int i = 0;i < N;i++){
    //     for(int j = 0;j <= MAX_SUM;j++){
    //         cout << DP[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
