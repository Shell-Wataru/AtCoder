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
    vector<pair<ll,ll>> data(N);
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
        data[i] = {minimum,total};
    }
    sort(data.begin(),data.end(),[](auto &l,auto &r){
        if ((r.first >= 0) != l.first >= 0){
            return (l.first >= 0) > (r.first >= 0);
        }else if(r.second >= 0 != l.second >= 0){
            return (l.second >= 0) > (r.second >= 0);
        }else if (r.first >= 0 && r.second >= 0){
            return r.first > l.first;
        }else if (r.first >= 0 && r.second < 0){
            return r.first > l.first;
        }else if (r.first < 0 && r.second >= 0){
            return l.first < r.first;
        }else if ((l.first == l.second) != (r.first == r.second)){
            return (l.first == l.second) < (r.first == r.second);
        }else if(l.first == l.second){
            return l.second > r.second;
        }else{
            return (l.second - l.first) > (r.second - r.first);
        }
    });
    // for(int i = 0;i < N;i++){
    //     cout << data[i].first <<"," << data[i].second << endl;
    // }
    ll all_total = 0;
    bool can_make = true;
    for(int i = 0; i< N;i++){
        if (all_total + data[i].first < 0){
            can_make = false;
        }
        all_total += data[i].second;
    }
    if (can_make && all_total == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}