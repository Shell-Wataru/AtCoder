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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

ll point(vector<string> &G,ll i,ll j){
    if ((i+j) % 2 == 0){
        return -('-' - G[i][j] - 1);
    }else{
        return ('-' - G[i][j] - 1);
    }
}
int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    vector<vector<ll>> DP(H,vector<ll>(W,0));
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if ((i+j) % 2 == 0){
                DP[i][j] = numeric_limits<ll>::min();
            }else{
                DP[i][j] = numeric_limits<ll>::max();
            }
        }
    }
    DP[H-1][W-1] = point(G,H-1,W-1);
    for(int i = H-1;i >= 0;i--){
        for(int j = W-1;j >= 0;j--){
            if ((i+j) % 2 == 0){
                if (i+1 < H){
                    DP[i][j] = max(DP[i][j],DP[i+1][j]  + point(G,i,j)) ;
                }
                if (j+1 < W){
                    DP[i][j] = max(DP[i][j],DP[i][j+1] + point(G,i,j)) ;
                }

            }else{
                if (i+1 < H){
                    DP[i][j] = min(DP[i][j],DP[i+1][j] + point(G,i,j));
                }
                if (j+1 < W){
                    DP[i][j] = min(DP[i][j],DP[i][j+1] + point(G,i,j));
                }
            }
        }
    }
    // for(int i = 0;i < H;i++){
    //     for(int j = 0;j < W;j++){
    //         cout << DP[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    ll result = DP[0][0] - point(G,0,0);
    if (result == 0) {
        cout << "Draw" << endl;
    }else if (result > 0){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
    return 0;
}