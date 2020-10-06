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

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    ll x0,a,p;
    cin >> x0 >> a >> p;
    vector<tuple<ll,ll,ll>> chairs;
    for(ll i = 0;i < N;i++){
        for(ll j = 0; j< M;j++){
            chairs.push_back(make_tuple(x0,i,j));
            x0 = (x0 + a) % p;
        }
    }
    sort(chairs.begin(),chairs.end());
    for(int i = 0;i < N;i++){
        sort(chairs.begin() + M * i,chairs.begin() + M * (i+1),[](tuple<ll,ll,ll> &l,tuple<ll,ll,ll> &r){
            return get<2>(l) < get<2>(r);
        });
    }

    // for(int i = 0;i < N;i++){
    //     for(int j = 0; j< M;j++){
    //         auto &c = chairs[M*i +j];
    //         cout << get<0>(c) << ",";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0; j< M;j++){
            auto &c = chairs[M*i +j];
            ans += abs(get<1>(c) - i) +abs(get<2>(c) - j);
        }
    }
    cout << ans << endl;
    return 0;
}