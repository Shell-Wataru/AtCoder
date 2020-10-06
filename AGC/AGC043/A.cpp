#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1e+9 + 7;
int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector<vector<ll>> DP(H,vector<ll>(W,0));
    for (int i = 0; i < H; i++)
    {
        cin >> S[i];
    }
    if(S[0][0] == '#'){
        DP[0][0] = 1;
    }else{
        DP[0][0] = 0;
    }
    for(int i = 1;i < H;i++){
        if (S[i-1][0] == '#' && S[i][0] == '#'){
            DP[i][0] = DP[i-1][0];
        }else if(S[i-1][0] == '#' && S[i][0] == '.'){
            DP[i][0] = DP[i-1][0];
        }else if(S[i-1][0] == '.' && S[i][0] == '#'){
            DP[i][0] = DP[i-1][0] + 1;
        }else{
            DP[i][0] = DP[i-1][0];
        }
    }
    for(int i = 1;i < W;i++){
        if (S[0][i-1] == '#' && S[0][i] == '#'){
            DP[0][i] = DP[0][i-1];
        }else if(S[0][i-1] == '#' && S[0][i] == '.'){
            DP[0][i] = DP[0][i-1];
        }else if(S[0][i-1] == '.' && S[0][i] == '#'){
            DP[0][i] = DP[0][i-1] + 1;
        }else{
            DP[0][i] = DP[0][i-1];
        }
    }
    for(int i = 1; i < H;i++){
        for (int j = 1; j < W; j++)
        {
            if(S[i][j] == '.'){
                DP[i][j] = min(DP[i-1][j],DP[i][j-1]);
            }else{
                if (S[i-1][j] == '#' && S[i][j-1] == '#'){
                    DP[i][j] = min(DP[i-1][j],DP[i][j-1]);
                }else if(S[i-1][j] == '#' && S[i][j-1] == '.'){
                    DP[i][j] = min(DP[i-1][j],DP[i][j-1] + 1);
                }else if(S[i-1][j] == '.' && S[i][j-1] == '#'){
                    DP[i][j] = min(DP[i-1][j]+1,DP[i][j-1]);
                }else{
                    DP[i][j] = min(DP[i-1][j] + 1,DP[i][j-1] + 1);
                }
            }
        }
    }
    cout << DP[H-1][W-1] << endl;
    return 0;
}