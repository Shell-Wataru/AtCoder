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
    ll B, C;
    cin >> B >> C;
    ll a,b,c,d;
    a = B - C / 2;
    if (C >= 2){
        b = B + (C - 2) / 2 + 1;
    }else{
        b = B + 1;
    }
    if (C >= 1){
        d = -B + (C - 1) / 2 + 1;
        c = -B - (C - 1) / 2;
    }else{
        d = -B;
        c = -B;
    }
    ll ans = b - a + d - c;
    ll duplicate = max(min(b, d) - max(a, c), 0ll);
    cout << ans - duplicate << endl;
    return 0;
}