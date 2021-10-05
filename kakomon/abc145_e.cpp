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
    ll N,T;
    scanf("%lld", &N);
    scanf("%lld", &T);
    vector<vector<ll>> forwardDP(N+1,vector<ll>(T+1,0));
    vector<vector<ll>> backwardDP(N+1,vector<ll>(T+1,0));
    vector<pair<ll,ll>>  dishes(N);
    // cout << "!!"<< endl;
    for(int i = 0;i < N;i++){
        cin >> dishes[i].first >> dishes[i].second;
    }
// cout << "!!"<< endl;
    for(int i = 0;i < N;i++){
        ll a = dishes[i].first;
        ll b = dishes[i].second;
        forwardDP[i+1] = forwardDP[i];
        for(int j = 0;j+a <= T;j++){
            forwardDP[i+1][j+a] = max(forwardDP[i+1][j+a],forwardDP[i+1][j+a-1]);
            forwardDP[i+1][j+a] = max(forwardDP[i+1][j+a],forwardDP[i][j] + b);
        }
    }
// cout << "!!"<< endl;
    for(int i = N;i > 0;i--){
        ll a = dishes[i-1].first;
        ll b = dishes[i-1].second;
        backwardDP[i-1] = backwardDP[i];
        for(int j = 0;j+a <= T;j++){
            backwardDP[i-1][j+a] = max(backwardDP[i-1][j+a],backwardDP[i-1][j+a-1]);
            backwardDP[i-1][j+a] = max(backwardDP[i-1][j+a],backwardDP[i][j] + b);
        }
    }
    // cout << "!!"<< endl;
    ll max_value = 0;
    for (int i = 0; i < N; i++)
    {
        ll a = dishes[i].first;
        ll b = dishes[i].second;
        for(int j = 0;j <= T-1;j++){
            max_value = max(max_value,forwardDP[i][T-1-j] + backwardDP[i+1][j] + b);
        }
    }
    cout << max_value << endl;
    return 0;
}