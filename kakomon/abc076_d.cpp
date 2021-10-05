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
    vector<ll> t(N);
    vector<ll> v(N);
    vector<ll> max_speed_from_front(N+1,0);
    vector<ll> max_speed_from_back(N+1,0);
    for (size_t i = 0; i < N; i++)
    {
        cin >> t[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= N;i++){
        if (i < N){
            max_speed_from_front[i] = min(min(max_speed_from_front[i-1] + t[i-1],v[i-1]),v[i]);
        }else{
            max_speed_from_front[i] = min(max_speed_from_front[i-1] + t[i-1],v[i-1]);
        }
    }
    for(int i = N-1; i >= 0;i--){
        if (i > 0){
            max_speed_from_back[i] = min(min(max_speed_from_back[i+1] + t[i],v[i]),v[i-1]);
        }else{
            max_speed_from_back[i] = min(max_speed_from_back[i+1] + t[i],v[i]);
        }
    }
    double ans = 0;
    for(int i = 0;i < N;i++){
        ll v1 = min(max_speed_from_front[i],max_speed_from_back[i]);
        ll v2 = min(max_speed_from_front[i+1],max_speed_from_back[i+1]);
        double max_v;
        if (v[i] >= 0.5* (v1 + v2 + t[i]) ){
            max_v = 0.5* (v1 + v2 + t[i]);
        }else{
            max_v = v[i];
        }
        ans +=  t[i] * max_v - 0.5 * (max_v - v1) * (max_v - v1) - 0.5 * (max_v - v2) * (max_v - v2);
    }
    cout <<fixed << setprecision(12) << ans << endl;
    return 0;
}