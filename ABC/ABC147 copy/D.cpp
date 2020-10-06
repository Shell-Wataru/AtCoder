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

ll BASE_NUM = 1000000007;
ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else if(y == 1){
        return x;
    }else{
        ll y_2 =my_pow(x,y/2) % BASE_NUM;
        ll yy = (y_2 * y_2) % BASE_NUM;
        if (y % 2 == 0){
            return yy;
        }else{
            return (yy * x) % BASE_NUM;
        }
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
            if (A[j] & (1LL<<i)){
                ones++;
            }else{
                zeros++;
            }
        }
        // cout << ones << " " << zeros << endl;
        ll patterns = ones * zeros % BASE_NUM;
        ll current_sum = patterns * my_pow(2,i) % BASE_NUM;
        value = (value + current_sum) % BASE_NUM;
    }

    cout << value << endl;

    return 0;
}