#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

double time(pair<ll,ll> &p,pair<ll,ll> &q, ll current,ll mask){
    return 1.0* (hypot(p.first - q.first,p.second - q.second))/(1ll<<(__builtin_popcountll(current & mask)));
}

int main()
{
    ll N,M;
    cin >> N >> M;
    N++;
    vector<pair<ll,ll>> P(N+M);
    for(int i = 1;i < N;i++){
        cin >> P[i].first >> P[i].second;
    }
    for(int i = 0;i < M;i++){
        cin >> P[N+i].first >> P[N+i].second;
    }
    vector<vector<double>> DP(1ll<<(N+M),vector<double>(N+M,numeric_limits<double>::max()));
    ll mask_m = ( (1ll<<(N+M)) - 1) - ((1ll<<N) - 1);
    ll mask_n = ((1ll<<N) - 1);
    // cout << mask_m << endl;
    // cout << mask_n << endl;
    DP[0][0] = 0;
    for(int i = 0;i < 1ll<<(N+M);i++){
        for(int j = 0;j < N+M;j++){
            if (DP[i][j] == numeric_limits<double>::max()){
                continue;
            }
            for(int k = 0;k < N+M;k++){
                if (i & 1ll<<k){
                    continue;
                }
                DP[i | 1ll<<k][k] = min(DP[i | 1ll<<k][k],DP[i][j] + time(P[j],P[k],i,mask_m));
            }
        }
    }
    double ans = numeric_limits<double>::max();
    for(int i = 0;i < 1ll<<(N+M);i++){
        if (__builtin_popcountll(i & mask_n) == N){
            ans = min(ans,DP[i][0]);
        }

    }
    cout << fixed << setprecision(12)  << ans << endl;
    return 0;
}