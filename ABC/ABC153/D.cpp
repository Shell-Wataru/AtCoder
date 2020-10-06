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

ll ans(ll h){
    if(h == 1){
        return 1;
    }else{
        return 2 * ans(h/2) + 1;
    }
}

int main()
{
    // 整数の入力
    ll H;
    cin >> H;
    cout << ans(H) << endl;
    return 0;
}