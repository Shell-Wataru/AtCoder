#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

double max_p(vector<pair<double,double>> &warters,ll K, double l, double r){
    if (abs(l-r) < 1e-10){
        return l;
    }
    double center = (l+r)/2;
    vector<double> DP(K+1,numeric_limits<double>::lowest()/2);
    DP[0] = 0;
    // cout << "!!!" << endl;
    for(auto &p:warters){
        // cout << p.first * p.second - p.first * center <<",";
        for(int i = K-1;i >=0;i--){
            DP[i+1] = max(DP[i+1],DP[i] + p.first * p.second - p.first * center);
        }
    }
    // cout << endl;
    // for(int i = 0;i <= K;i++){
    //     cout << DP[i] << ",";
    // }
    // cout << endl;

    if (DP[K] > 0){
        return max_p(warters,K,center,r);
    }else{
        return max_p(warters,K,l,center);
    }
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<pair<double,double>> warters(N);
    for(int i =0;i < N;i++){
        cin >> warters[i].first >> warters[i].second;
    }
    cout << fixed << setprecision(12) << max_p(warters,K,0,100) << endl;
    return 0;
}