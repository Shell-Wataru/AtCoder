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
    vector<ll> a(N);
    vector<ll> ans(N,0);
    vector<pair<ll,ll>> data(N);
    for(int i = 0;i < N;i++){
        cin >> a[i];
        data[i].first = a[i];
        data[i].second = i;
    }
    sort(data.begin(),data.end(),greater<pair<ll,ll>>());
    data.push_back({0,numeric_limits<ll>::max()});
    ll remain = 0;
    ll min_x = numeric_limits<ll>::max();
    for(ll i = 0;i < N;i++){
        min_x = min(min_x, data[i].second);
        if(data[i+1].first == data[i].first){
            continue;
        }else{
            ans[min_x] += (data[i].first - data[i+1].first) * (i+1);
        }
    }
    for(int i = 0;i < N;i++){
        cout << ans[i] << endl;
    }
    return 0;
}