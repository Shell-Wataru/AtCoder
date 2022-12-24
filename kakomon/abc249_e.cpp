#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N, P;
    cin >> N >> P;
    vector<vector<ll>> DP(N+10,vector<ll>(N+2,0));
    DP[0][0] = 1;
    DP[0][1] = P-1;
    for(int i = 0;i <= N;i++){
        ll base;
        if (i == 0){
            base = 26;
        }else{
            base = 25;
        }
        for(ll j = 0;j <= N;j++){
            DP[i][j+1] += DP[i][j];
            DP[i][j+1] %= P;
        }
        for(ll j = 0;j <= N;j++){
            DP[i+2][min(j+1,N+1)] += DP[i][j] * base;
            DP[i+2][min(j+10,N+1)] += P - DP[i][j] * base % P;
            DP[i+3][min(j+10,N+1)] += DP[i][j] * base;
            DP[i+3][min(j+100,N+1)] += P - DP[i][j] * base % P;
            DP[i+4][min(j+100,N+1)] += DP[i][j] * base;
            DP[i+4][min(j+1000,N+1)] += P - DP[i][j] * base % P;
            DP[i+5][min(j+1000,N+1)] += DP[i][j] * base;
            DP[i+5][min(j+10000,N+1)] += P - DP[i][j] * base % P;
        }
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        ans += DP[i][N];
        ans %= P;
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
