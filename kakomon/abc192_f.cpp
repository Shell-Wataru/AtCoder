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

ll answer(vector<ll> &A,ll N, ll X,ll K){
    vector<vector<ll>> DP(K+1,vector<ll>(K,numeric_limits<ll>::min()/2));
    DP[0][X%K] = 0;
    for(int i = 0;i < N;i++){
        vector<vector<ll>> newDP = DP;
        for(int j = 0;j < K;j++){
            for(int k = 0;k < K;k++){
                if (DP[j][k] != numeric_limits<ll>::min()/2){
                    newDP[j+1][(X - (DP[j][k] + A[i]))% K] = max(newDP[j+1][(X - (DP[j][k] + A[i]))% K], DP[j][k] + A[i]);
                }

            }
        }
        DP = newDP;
    }
    if (DP[K][0] == numeric_limits<ll>::min()/2){
        return -1;
    }else{
        return (X - DP[K][0])/K;
    }

}
int main()
{
    ll N,X;
    cin >> N >> X;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 1;i <= N;i++){
        ll a = answer(A,N,X,i);
        if (a != -1){
            ans = min(ans,a);
        }
    }
    cout << ans << endl;
    return 0;
}