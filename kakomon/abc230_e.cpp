#include<iostream>
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
    ll ans = 0;
    for(ll i = 1;i * i <= N;i++){
        if (i== N/i){
            ans += N/i;
        }else{
            ll a = N/i;
            ll b = N/(i+1);
            // cout << i << ":" << a << "~" << b << endl;
            ans += i * (a-b);
            ans += N/i;
        }
    }
    cout << ans << endl;
    // ll naive = 0;
    // for(int i = 1;i <= N;i++){
    //     naive += N/i;
    //     cout << N/i;
    // }
    // cout << endl;
    // cout << naive << endl;
    return 0;
}