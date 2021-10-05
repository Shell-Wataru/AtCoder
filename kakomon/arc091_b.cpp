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
    ll ans = 0;
    for(int b = K+1;b <= N;b++){
        ll n = N/b;
        ll remain = N - b * n;
        if (K != 0){
            ans += n * (b- K) + max(remain - K + 1,0ll);
        }else{
            ans += n * (b- K) + remain;
        }

    }
    cout << ans << endl;
    return 0;
}