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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    scanf("%lld", &N);
    if (N % 2 == 1){
        cout << 0 << endl;
    }else{
        N /= 2;
        ll ans = 0;
        while(N > 0){
            ans += N/5;
            N/= 5;
        }
        cout << ans << endl;
    }
    return 0;
}