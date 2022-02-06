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
    ll N,M;
    cin >> N >> M;
    vector<ll> w(N);
    for(int i = 0;i < N;i++){
        cin >> w[i];
    }
    sort(w.begin(),w.end());
    ll largest = w.back();
    w.pop_back();
    ll second_largest = w.back();
    w.pop_back();
    vector<pair<ll,ll>> lv(M);
    for(int i = 0;i < N;i++){
        cin >> lv[i].first >> lv[i].second;
    }
    sort(lv.begin(),lv.end());
    ll ans = numeric_limits<ll>::max();
    do {
        vector<pair<ll,ll>> orders;
        orders.push_back({largest,0});
        for(int i = 0;i < N-2;i++){
            orders.push_back({w[i],0});
        }
        orders.push_back({second_largest,0});
        bool can_make = true;
        for(int i = 0;i < M;i++){
            ll weight = 0;
            ll current_length = 0;
            ll l = -1;

            for(int r = 0;r < N;r++){
                while
                if (current_length + orders[r].second < lv[i].first && weight + w[r] <= lv[i].first){
                    current_length += orders[r].second;
                    weight += w[r];
                }else if (current_length + orders[r].second >= lv[i].first && weight + w[r] <= lv[i].first){
                    current_length += orders[r].second;
                    current_length -= orders[l+1].second;
                    weight += w[r];
                    weight -= w[l];
                }else{
                    current_length -= orders[l+1].second;
                    weight -= w[l];
                }
            }

        }
    }while(next_permutation(w.begin(),w.end()));
    return 0;
}