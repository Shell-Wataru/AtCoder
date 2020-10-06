#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    if (2 * a < b){
      cout << a * abs(x) + a * abs(y) << endl;
    }else{
      cout << a *abs(x - y)  + b * min(abs(x),abs(y)) << endl;
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}