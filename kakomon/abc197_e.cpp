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
    ll N;
    cin >> N;
    vector<pair<ll,ll>> balls(N+1,{numeric_limits<ll>::max(),numeric_limits<ll>::min()});
    for(int i = 0;i < N;i++){
        ll x,c;
        cin >> x >> c;
        c--;
        balls[c].first = min(balls[c].first,x);
        balls[c].second = max(balls[c].second,x);
    }
    balls[N] = {0,0};
    pair<ll,ll> current = {0,0};
    vector<vector<ll>> DP(2,vector<ll>(N+2,0));
    for(int i = 0;i <= N;i++){
        if (balls[i].first == numeric_limits<ll>::max()){
            DP[0][i+1] = DP[0][i];
            DP[1][i+1] = DP[1][i];
            continue;
        }else{
            ll d = balls[i].second - balls[i].first;
            DP[0][i+1] = min(DP[0][i] + abs(current.first - balls[i].second) + d, DP[1][i] + abs(current.second - balls[i].second) + d);
            DP[1][i+1] = min(DP[0][i] + abs(current.first - balls[i].first) + d, DP[1][i] + abs(current.second - balls[i].first) + d);
            current = balls[i];
        }
    }
    for(int i = 0;i <= N;i++){
        if (balls[i].first == numeric_limits<ll>::max()){
            continue;
        }else{
            ll d = balls[i].second - balls[i].first;
            DP[0][i+1] = min(DP[0][i] + abs(current.first - balls[i].second) + d, DP[1][i] + abs(current.second - balls[i].second) + d);
            DP[1][i+1] = min(DP[0][i] + abs(current.first - balls[i].first) + d, DP[1][i] + abs(current.second - balls[i].first) + d);
            current = balls[i];
        }
    }
    cout << DP[0][N+1] << endl;
    return 0;
}