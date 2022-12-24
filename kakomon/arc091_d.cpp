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
    ll N;
    cin >> N;
    ll x= 0;
    for(int i = 0;i < N;i++){
        ll a,K;
        cin >> a >> K;
        if (a < K){
            continue;
        }
        while(a % K != 0){
            ll target = (a/K) * K;
            ll d = a/K + 1;
            ll times = (a-target+d-1)/d;
            a -= d*times;
        }
        x ^=  a/K;
    }
    if (x == 0){
        cout << "Aoki" << endl;
    }else{
        cout << "Takahashi" << endl;
    }
    return 0;
}