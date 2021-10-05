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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll W,N,K;
    scanf("%lld", &W);
    scanf("%lld", &N);
    scanf("%lld", &K);
    vector<vector<vector<ll>>> DP(N+1,vector<vector<ll>>(K+1,vector<ll>(W+1,numeric_limits<ll>::min())));
    DP[0][0][0] = 0;
    for(int i = 0;i < N;i++){
        ll a,b;
        cin >> a >> b;
        DP[i+1] = DP[i];
        for(int j = 0;j+a <= W;j++){
            for(int k = 0;k < K;k++){
                DP[i+1][k+1][j+a] = max(DP[i+1][k+1][j+a],DP[i][k][j] + b);
                // cout << DP[i+1][k+1][j+a] << endl;
            }
        }
    }
    ll max_value = 0;
    for(int j = 0;j <= W;j++){
        for(int k = 0;k <= K;k++){
            max_value = max(max_value,DP[N][k][j]);
        }
    }
    cout << max_value << endl;
    return 0;
}