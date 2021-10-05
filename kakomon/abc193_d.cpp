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

ll score(string &S){
    vector<ll> count(10,0);
    vector<ll> power = {1,10,100,1000,10000,100000};
    for(auto c:S){
        count[c-'0']++;
    }
    ll v = 0;
    for(int i = 1;i <= 9;i++){
        v += i * power[count[i]];
    }
    return v;
}

int main()
{
    // 整数の入力
    ll K;
    cin >> K;
    string S,T;
    cin >> S >> T;
    vector<ll> remain_count(10,K);
    for(int i = 0;i < 4;i++){
        remain_count[S[i]- '0']--;
        remain_count[T[i]- '0']--;
    }
    double ans = 0;
    ll total_patterns =(9*K - 8)*(9*K - 9);
    for(int i = 1; i <= 9;i++){
        for(int j = 1; j <= 9;j++){
            S[4] = '0'+i;
            T[4] = '0'+j;
            ll patterns = remain_count[i];
            remain_count[i]--;
            patterns *= remain_count[j];
            if (score(S) > score(T)){
                ans += 1.0/ total_patterns * patterns;
            }
            remain_count[i]++;
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}