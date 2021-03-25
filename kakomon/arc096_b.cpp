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
    // 整数の入力
    ll N,C;
    cin >> N >> C;
    vector<pair<ll,ll>> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a.begin(),a.end());
    vector<ll> right_maxes(N);
    vector<ll> left_maxes(N);
    ll current = 0;
    ll max_calory = 0;
    ll back_max = 0;
    ll back_max_index = -1;
    for(int i = 0;i < N;i++){
        current +=  a[i].second;
        max_calory = max(max_calory,current - 2 * a[i].first);
        right_maxes[i] = max_calory;
    }
    current = 0;
    max_calory = 0;
    for(int i = N-1;i >= 0;i--){
        current +=  a[i].second;
        max_calory = max(max_calory,current - 2 * (C - a[i].first));
        left_maxes[i] = max_calory;
    }
    current = 0;
    max_calory = 0;
    for(int i = 0;i < N;i++){
        current +=  a[i].second;
        if (i+1 < N){
            max_calory = max(max_calory,current - a[i].first + left_maxes[i+1]);
        }else{
            max_calory = max(max_calory,current - a[i].first);
        }

    }

    current = 0;
    for(int i = N-1;i >= 0;i--){
        current +=  a[i].second;
        if (i-1 >= 0){
            max_calory = max(max_calory,current - (C - a[i].first) + right_maxes[i-1]);
        }else{
            max_calory = max(max_calory,current - (C - a[i].first));
        }
    }
    cout << max_calory << endl;
    return 0;
}