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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll R,C,K;
    cin >> R >> C >> K;
    vector<vector<ll>> G(R,vector<ll>(C,0));
    for(int i = 0;i < K;i++){
        ll r,c,v;
        cin >> r >> c >> v;
        r--;
        c--;
        G[r][c] = v;
    }
    vector<vector<vector<ll>>> DP(R,vector<vector<ll>>(C,vector<ll>(4,0)) );
    for(int i = 0; i < R;i++){
        for(int j = 0;j < C;j++){
            if (i != 0){
                for(int k = 0;k <= 3;k++){
                    DP[i][j][0] = max(DP[i][j][0],DP[i-1][j][k]);
                }
            }
            if (j != 0){
                for(int k = 0;k <= 3;k++){
                    DP[i][j][k] = max(DP[i][j][k],DP[i][j-1][k]);
                }
            }
            for(int k = 3;k >= 1;k--){
                DP[i][j][k] = max(DP[i][j][k],DP[i][j][k-1] + G[i][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i <= 3;i++){
        ans = max(ans,DP[R-1][C-1][i]);
    }
    cout << ans << endl;
    return 0;
}