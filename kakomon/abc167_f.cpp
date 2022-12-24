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
    ll N;
    cin >> N;
    vector<pair<ll,ll>> data_bigger;
    vector<pair<ll,ll>> data_same;
    vector<pair<ll,ll>> data_smaller;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        ll minimum = 0;
        ll total = 0;
        for(auto &c:s){
            if (c == '('){
                total++;
            }else{
                total--;
            }
            minimum = min(minimum,total);
        }
        if (total > 0){
            data_bigger.push_back({minimum,total});
        }else if (total == 0 ){
            data_same.push_back({minimum,total});
        }else{
            data_smaller.push_back({minimum-total,-total});
        }
    }
    sort(data_bigger.rbegin(),data_bigger.rend());
    sort(data_smaller.begin(),data_smaller.end());
    ll all_total = 0;
    bool can_make = true;
    for(auto p:data_bigger){
        ll min_v = all_total + p.first;
        if (min_v < 0){
            can_make = false;
        }
        all_total += p.second;
    }
    for(auto p:data_same){
        ll min_v = all_total + p.first;
        if (min_v < 0){
            can_make = false;
        }
        all_total += p.second;
    }
    for(auto p:data_smaller){
        ll minimum = p.first - p.second;
        ll total = - p.second;
        ll min_v = all_total + minimum;
        if (min_v < 0){
            can_make = false;
        }
        all_total += total;
    }
    if (can_make && all_total == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}