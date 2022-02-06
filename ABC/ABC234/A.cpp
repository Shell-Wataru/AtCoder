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

using namespace std;
using ll = long long;

ll f(ll x){
    return x*x + 2* x + 3;
}

int main()
{
    // 整数の入力
    ll x;
    cin >> x;
    cout << f(f(f(x) + x) + f(f(x))) << endl;
    return 0;
}