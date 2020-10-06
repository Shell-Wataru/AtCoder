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

using namespace std;

int main()
{
    // 整数の入力
    ll N,Q;
    cin >> N;
    // DP[i][j][k]
    vector<ll> A(3*N);
    for(int i = 0;i < 3*N;i++){
        cin >> A[i];
        A[i]--;
    }
    vector<vector<vector<ll>>> DP(N+1,vector<vector<ll>>(N,vector<ll>(N,numeric_limits<ll>::min())));
    DP[0][A[0]][A[1]] = 0;
    for(int i = 0;i < N-1;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                vector<ll> permu = {j,k,A[3*i+2],A[3*i+3],A[3*i+4]};
                vector<ll> comb = {0,0,0,1,1};
                do{
                    ll min_remain = numeric_limits<ll>::max();
                    ll max_remain = numeric_limits<ll>::min();
                    if (permu[0] == permu[1] && permu[1] == permu[2]){
                        DP[i+1][permu[3]][permu[4]] = max(DP[i+1][permu[3]][permu[4]], DP[i][j][k] + 1);
                    }else{
                        DP[i+1][permu[3]][permu[4]] = max(DP[i+1][permu[3]][permu[4]], DP[i][j][k]);
                    }
                }while(next_permutation(comb.begin(),comb.end()));
            }
        }
    }
    ll ans = 0;
    for(int j = 0;j < N;j++){
        for(int k = 0;k < N;k++){
            if (j == k  && k == A[3*N -1]){
                ans = max(ans,DP[N-1][j][k] + 1);
            }else{
                ans = max(ans,DP[N-1][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}