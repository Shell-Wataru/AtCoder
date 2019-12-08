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

ll BASE_NUM = 998244353;
ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else if(y == 1){
        return x;
    }else{
        return (my_pow(x,y/2) % BASE_NUM) * (my_pow(x,(y+1)/2) % BASE_NUM) % BASE_NUM;
    }
}

int main()
{
    // 整数の入力
    ll N;
    vector<ll> A;
    cin >> N;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    ll value = 0;
    for(int i = 0;i<60;i++){
        ll ones = 0;
        ll zeros = 0;
        for(int j = 0;j<N;j++){
            if (A[j] & (1<<i)){
                ones++;
            }else{
                zeros++;
            }
        }
        value = value +
    }

    cout << total << endl;

    return 0;
}