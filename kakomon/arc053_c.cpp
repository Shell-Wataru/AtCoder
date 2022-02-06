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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<pair<ll,ll>> plus;
    vector<pair<ll,ll>> same;
    vector<pair<ll,ll>> minus;
    for(int i = 0;i < N;i++){
        ll a,b;
        cin >> a >> b;
        if (a > b){
            plus.push_back({b,a});
        }else if (a == b){
            same.push_back({a,b});
        }else{
            minus.push_back({a,b});
        }
    }
    sort(minus.begin(),minus.end());
    sort(plus.begin(),plus.end());
    reverse(plus.begin(),plus.end());
    ll x = 0;
    ll current = 0;
    for(auto m:minus){
        x = max(x, current+ m.first);
        current += m.first - m.second;
    }
    for(auto m:same){
        x = max(x, current+ m.first);
        current += m.first - m.second;
    }
    for(auto m:plus){
        // cout << m.first << "," << m.second << endl;
        x = max(x, current+ m.second);
        current += m.second - m.first;
    }
    cout << x << endl;
    return 0;
}