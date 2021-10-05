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

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> counts(310,numeric_limits<ll>::max());
    for(int i = 0;i < 3;i++){
        ll ng;
        cin >> ng;
        counts[ng] = -1;
    }
    for(int i = 300;i >= 0;i--){
        if (counts[i] == -1){
            continue;
        }else if (i == N){
            counts[i] = 0;
        }else{
            for(int j = 1;j <= 3;j++){
                if (counts[i+j] == -1 || counts[i+j] == numeric_limits<ll>::max()){
                    continue;
                }else{
                    counts[i] = min(counts[i],counts[i+j]+1);
                }
            }
        }
    }
    if (counts[0] != -1 && counts[0] <= 100){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}