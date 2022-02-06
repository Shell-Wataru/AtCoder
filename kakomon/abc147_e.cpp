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
#include <climits>
using namespace std;
using ll = long long;

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    ll half = 80*80;
    vector<vector<vector<bool>>> DP(H, vector<vector<bool>>(W,vector<bool>(half*2+1,false)));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> B[i][j];
        }
    }
    DP[0][0][half+A[0][0]-B[0][0]] = true;
    DP[0][0][half-A[0][0]+B[0][0]] = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i != 0){
                for(int k = 0;k < 2*half+1;k++){
                    if (0<= k+A[i][j]-B[i][j] &&k+A[i][j]-B[i][j] < 2*half+1){
                        DP[i][j][k+A[i][j]-B[i][j]] = DP[i][j][k+A[i][j]-B[i][j]] || DP[i-1][j][k];
                    }
                    if (0 <= k-A[i][j]+B[i][j] && k-A[i][j]+B[i][j] < 2*half+1){
                        DP[i][j][k-A[i][j]+B[i][j]] = DP[i][j][k-A[i][j]+B[i][j]] || DP[i-1][j][k];
                    }
                }
            }
            if (j != 0){
                for(int k = 0;k < 2*half+1;k++){
                    if (0<= k+A[i][j]-B[i][j] && k+A[i][j]-B[i][j] < 2*half+1){
                        DP[i][j][k+A[i][j]-B[i][j]] = DP[i][j][k+A[i][j]-B[i][j]] || DP[i][j-1][k];
                    }
                    if (0 <= k-A[i][j]+B[i][j] && k-A[i][j]+B[i][j] < 2*half+1){
                        DP[i][j][k-A[i][j]+B[i][j]] = DP[i][j][k-A[i][j]+B[i][j]] || DP[i][j-1][k];
                    }
                }
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    for(int k = 0;k < 2*half+1;k++){
        if (DP[H-1][W-1][k]){
            ans = min(ans,abs(k-half));
        }
    }
    cout << ans << endl;
    return 0;
}