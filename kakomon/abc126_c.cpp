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

int main()
{
    ll N,K;
    scanf("%lld", &N);
    scanf("%lld", &K);
    vector<double> DP(K);
    for(int i = K-1;i >= 1;i--){
        if (2*i >= K){
            DP[i] = 1.0/2;
        }else{
            DP[i] = DP[2*i]/2;
        }
    }
    double ans = 0;
    for(int i = N;i >= 1;i--){
        if (i >= K){
            ans += 1.0/N;
        }else{
            ans += DP[i]/N;
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}