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

ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,L;
    cin >> N >> L;
    vector<ll> DP(L+1,BASE_NUM);
    vector<ll> X(L+1,0);
    DP[0] = 0;
    for(int i = 0;i < N;i++){
        ll x;
        cin >> x;
        X[x] = 1;
    }
    ll T1,T2,T3;
    cin >> T1 >> T2 >> T3;
    for(int i = 1;i <= L;i++){
        if (X[i] == 0){
            DP[i] = min(DP[i],DP[i-1] + T1);
            if (i >= 2){
                DP[i] = min(DP[i],DP[i-2] + T1 + T2);
            }
            if (i >= 4){
                DP[i] = min(DP[i],DP[i-4] + T1 + 3 * T2);
            }
        }else{
            DP[i] = min(DP[i],DP[i-1] + T1 + T3);
            if (i >= 2){
                DP[i] = min(DP[i],DP[i-2] + T1 + T2 + T3);
            }
            if (i >= 4){
                DP[i] = min(DP[i],DP[i-4] + T1 + 3 * T2 + T3);
            }
        }
    }
    ll min_t = DP[L];
    for(int i = 1;i <=3;i++){
        if (L >= i){
            min_t = min(min_t,DP[L-i] + T1/2 + (2 * i * T2 - T2)/2);
        }
    }
    cout << min_t <<endl;
    return 0;
}