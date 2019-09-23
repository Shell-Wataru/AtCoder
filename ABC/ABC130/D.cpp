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
namespace mp = boost::multiprecision;

ll index(vector<ll> &ruiseki,ll K, ll i,ll r,ll l){
    if (r+1 == l){
        // cout << ruiseki[l] << endl;
        if(ruiseki[l] - ruiseki[i] >= K ){
            return l;
        }else{
            return -1;
        }
    }
    ll center = (r + l)/2;
    if(ruiseki[center] - ruiseki[i] >= K){
        return index(ruiseki,K,i,r,center);
    }else{
        return index(ruiseki,K,i,center,l);
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll N,K,c,renzoku;
    cin >> N >> K;
    c = 0;
    renzoku = 0;
    vector<ll> ruiseki;

    ruiseki.push_back(0);
    for(int i = 1;i<=N;i++){
        ll a;
        cin >> a;
        ruiseki.push_back(ruiseki[i-1] + a);
    }

    for(int i = 0;i<N;i++){
        ll clear_index =  index(ruiseki,K,i,i,N+1);
        // cout << i <<":"<< clear_index << endl;
        if (clear_index == -1){
            break;
        }else{
            c += N + 1 - clear_index;
        }
    }

    cout << c << endl;
    return 0;

}