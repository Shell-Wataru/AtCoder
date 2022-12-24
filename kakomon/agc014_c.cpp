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

int main()
{
    ll H,W,K;
    cin >> H >> W >> K;
    ll max_open = min(H/2,W/2);
    vector<vector<ll>> DP(H,vector<ll>(W,numeric_limits<ll>::max()/2));
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    queue<vector<ll>> q;

    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if (G[i][j] == 'S'){
                q.push({0,i,j});
            }
        }
    }
    vector<pair<ll,ll>> directions ={
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    while(!q.empty()){
        ll d = q.front()[0];
        ll h = q.front()[1];
        ll w = q.front()[2];
        q.pop();
        if (d < DP[h][w]){
            DP[h][w] = d;
            for(auto dir:directions){
                ll next_h = h + dir.first;
                ll next_w = w + dir.second;
                if(0 <= next_h && next_h < H && 0 <= next_w && next_w < W && G[next_h][next_w] == '.'){
                    q.push({d+1,next_h,next_w});
                }
            }
        }
    }
    ll ans = numeric_limits<ll>::max()/2;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(DP[i][j] > K){
                ans = min(ans, (DP[i][j] + i + K - 1)/K );
                ans = min(ans, (DP[i][j] + j + K - 1)/K );
                ans = min(ans, (DP[i][j] + H- 1 - i + K - 1)/K );
                ans = min(ans, (DP[i][j] + W- 1 - j + K - 1)/K );
            }else{
                ans = min(ans, 1 + (i + K - 1)/K );
                ans = min(ans, 1 + (j + K - 1)/K );
                ans = min(ans, 1 + (H- 1 - i + K - 1)/K );
                ans = min(ans, 1 + (W- 1 - j + K - 1)/K );
            }
        }
    }
    cout << ans << endl;

    // for(int i = 0;i < H;i++){
    //     for(int j = 0;j < W;j++){
    //         cout << MinDP[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    return 0;
}