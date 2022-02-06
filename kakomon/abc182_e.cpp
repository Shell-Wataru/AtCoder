#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll H,W,N,M;
    cin >> H >> W >> N >> M;
    vector<vector<ll>> G(H,vector<ll>(W,0));
    vector<vector<ll>> result(H,vector<ll>(W,0));
    for(int i = 0;i  < N;i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = 1;
    }
    for(int i = 0;i  < M;i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = 2;
    }

    for(int i = 0;i  < H;i++){
        bool light = false;
        for(int j = 0;j < W;j++){
            if (G[i][j] == 1){
                light = true;
            }else if (G[i][j] == 2){
                light = false;
            }
            if (light){
                result[i][j] = 1;
            }
        }
    }

    for(int i = 0;i  < H;i++){
        bool light = false;
        for(int j = W-1;j >= 0;j--){
            if (G[i][j] == 1){
                light = true;
            }else if (G[i][j] == 2){
                light = false;
            }
            if (light){
                result[i][j] = 1;
            }
        }
    }

    for(int i = 0;i  < W;i++){
        bool light = false;
        for(int j = H-1;j >= 0;j--){
            if (G[j][i] == 1){
                light = true;
            }else if (G[j][i] == 2){
                light = false;
            }
            if (light){
                result[j][i] = 1;
            }
        }
    }

    for(int i = 0;i  < W;i++){
        bool light = false;
        for(int j = 0;j < H;j++){
            if (G[j][i] == 1){
                light = true;
            }else if (G[j][i] == 2){
                light = false;
            }
            if (light){
                result[j][i] = 1;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i  < H;i++){
        for(int j = 0;j < W;j++){
            ans += result[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}