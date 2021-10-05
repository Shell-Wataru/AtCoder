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

ll value(ll N,ll K,ll start, vector<ll> &P, vector<ll> &C){
    ll max_point = numeric_limits<ll>::min();
    ll point = 0;
    ll current = start;
    ll period = 0;
    ll total_c = 0;
    for(int i = 0;i < N;i++){
        period++;
        current = P[current];
        total_c += C[current];
        if (current == start){
            break;
        }
    }
    // cout << current << endl;
    // cout << period  << "," << total_c<< endl;
    if (total_c > 0){
        if (K > period){
            ll base_times = K/period - 1;
            ll base_point = total_c * base_times;
            for(int j = 0;j< period + K % period;j++){
                current = P[current];
                point += C[current];
                max_point = max(max_point, point + base_point);
            }
        }else{
            for(int j = 0;j< min(period,K);j++){
                current = P[current];
                point += C[current];
                max_point = max(max_point, point);
            }
        }
    }else{
        for(int j = 0;j< min(period,K);j++){
            current = P[current];
            point += C[current];
            max_point = max(max_point, point);
        }
    }
    return max_point;
}
int main()
{
    ll N,K;
    cin >> N >> K;
    vector<ll> P(N);
    vector<ll> C(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> P[i];
        P[i]--;
    }
    ll total_c = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> C[i];
        total_c += C[i];
    }

    ll max_point = numeric_limits<ll>::min();
    for(int i = 0;i < N;i++){
        max_point = max(max_point, value(N,K,i,P,C));
    }
    cout << max_point << endl;
    return 0;
}