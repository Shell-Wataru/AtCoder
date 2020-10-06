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
namespace mp = boost::multiprecision;


int main()
{
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    vector<double> Sums;
    Sums.push_back(0);
    for(int i = 0; i< N;i++){
        double p;
        cin >> p;
        Sums.push_back(Sums.back() + (p+1)/2);
        // cout << Sums.back() << endl;
    }
    double ans = 0;
    for(int i = 0; i<= N - K;i++){
        // cout << Sums[i] << "," << Sums[i+K] << ":" << Sums[i+K] - Sums[i] << endl;
        ans = max(ans, Sums[i+K] - Sums[i]);
        // cout << ans << endl;
    }
    cout << fixed << setprecision(12) << ans << endl;;
    return 0;
}