#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> WhiteSums(H+1,vector<ll>(W+1,0));
    vector<vector<ll>> BlackSums(H+1,vector<ll>(W+1,0));
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            ll a;
            cin >> a;
            if ((i+j) % 2 == 1){
                WhiteSums[i+1][j+1] = a;
            }else{
                BlackSums[i+1][j+1] = a;
            }
        }
    }
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            WhiteSums[i][j] += WhiteSums[i-1][j] + WhiteSums[i][j-1] - WhiteSums[i-1][j-1];
            BlackSums[i][j] += BlackSums[i-1][j] + BlackSums[i][j-1] - BlackSums[i-1][j-1];
        }
    }

    int max_s = 0;
    for(int x1 = 0;x1 < H;x1++){
        for(int y1 = 0; y1 < W;y1++){
            for(int x2 = x1 + 1; x2 <= H;x2++){
                for(int y2 = y1 + 1; y2 <= W;y2++){
                    ll white_sum = WhiteSums[x2][y2] - WhiteSums[x2][y1] - WhiteSums[x1][y2] + WhiteSums[x1][y1];
                    ll black_sum = BlackSums[x2][y2] - BlackSums[x2][y1] - BlackSums[x1][y2] + BlackSums[x1][y1];
                    if (white_sum == black_sum){
                        max_s = max(max_s,(x2 - x1) * (y2 -y1));
                    }
                }
            }
        }
    }
    cout << max_s << endl;

   return 0;
}