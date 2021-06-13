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
    cin >> N;
    vector<ll> A(N+1);
    for(int i = 1;i <= N;i++){
        cin >> A[i];
    }

    ll before = 0;
    ll ans = 0;
    for(int i = 1;i <= N;i++){
        ans += (before + A[i])/2;
        if (A[i] > 0){
            before = (before + A[i])%2;
        }else{
            before = 0;
        }

    }
    cout << ans << endl;
    return 0;
}