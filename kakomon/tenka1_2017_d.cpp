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
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i =0 ;i < N;i++){
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for(int i = 0;i <= 30;i++){
        ll k;
        if (i == 0){
            k = K;
        }else if (K & 1ll<<i){
            k = (K - (1ll<<i)) | ( (1ll<<i) - 1);
        }else{
            continue;
        }
        ll value = 0;
        for(int j = 0;j < N;j++){
            if ((k & A[j]) == A[j]){
                value += B[j];
            }
        }
        ans = max(ans,value);
    }
    cout << ans << endl;
    return 0;
}