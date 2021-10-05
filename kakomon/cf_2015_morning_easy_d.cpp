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
#include <stack>

using namespace std;
using ll = long long;

int solve(){
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    for(int i = 1;i < N;i++){
        vector<vector<ll>> DP(i,vector<ll>(N-i,0));

        for(int j = 0;j < i;j++){
            for(int k = i;k < N;k++){
                if (j != 0){
                    DP[j][k-i] = max(DP[j][k-i],DP[j-1][k-i]);
                }

                if (k-i != 0){
                    DP[j][k-i] = max(DP[j][k-i],DP[j][k-i-1]);
                }
                if (S[j] == S[k]){
                    if (j == 0 || k-i == 0){
                        DP[j][k-i] = max(DP[j][k-i],1ll);
                    }else{
                        DP[j][k-i] = max(DP[j][k-i],DP[j-1][k-i-1] + 1ll);
                    }
                }
            }
        }
        ans = max(ans,DP[i-1][N-i-1]);
    }
    // cout << ans << endl;
    cout << N - 2 * ans << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll T;
    // cin >> T;
    // for (size_t i = 0; i < T; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}