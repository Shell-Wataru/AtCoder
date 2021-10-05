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

ll dfs(vector<vector<ll>> &G,ll current){
    vector<ll> odd_values;
    vector<ll> odd_positive_values;
    ll even_negative_total = 0;
    ll even_positive_total = 0;
    for(auto to:G[current]){
        ll p = dfs(G,to);
        if (p % 2 == 0){
            if (p > 0){
                even_positive_total += p;
            }else if(p< 0){
                even_negative_total += p;
            }
        }else{
                odd_values.push_back(p);
        }
    }
    sort(odd_values.begin(),odd_values.end());
    ll ans = 1 + even_negative_total;
    bool opponent_choose = true;
    for(int i = 0;i < odd_values.size();i++){
        if (i%2 == 0){
            ans += odd_values[i];
        }else{
            ans += - odd_values[i];
        }
    }
    if (odd_values.size() % 2 == 0){
        ans += even_positive_total;
    }else{
        ans += - even_positive_total;
    }
    return ans;
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (size_t i = 1; i < N; i++)
    {
        ll v;
        cin >> v;
        v--;
        G[v].emplace_back(i);
    }
    cout <<  (N + dfs(G,0))/2 << endl;
    return 0;
}