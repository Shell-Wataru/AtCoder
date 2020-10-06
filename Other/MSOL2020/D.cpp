#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%lld",&A[i]);
    }
    vector<pair<ll,ll>> money_kabus;
    money_kabus.push_back({1000,0});
    for (size_t i = 0; i < N; i++)
    {
        vector<pair<ll,ll>> next_money_kabus(money_kabus);
        for(auto &p:money_kabus){
            next_money_kabus.push_back({p.first + p.second * A[i], 0});
            next_money_kabus.push_back({p.first % A[i], p.second + p.first/A[i]});
        }
        sort(next_money_kabus.begin(),next_money_kabus.end());
        money_kabus.clear();
        for(auto &p:next_money_kabus){
            if (money_kabus.empty()){
                money_kabus.push_back(p);
            }else{
                if (money_kabus.back().first <= p.first && money_kabus.back().second <= p.second){
                    money_kabus.pop_back();
                    money_kabus.push_back(p);
                }else{
                    money_kabus.push_back(p);
                }
            }
        }
    }
    cout << money_kabus.back().first << endl;
    return 0;
}