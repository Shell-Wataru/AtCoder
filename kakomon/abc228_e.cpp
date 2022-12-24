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

const long long BASE_NUM = 998244353;

ll pow(ll x, ll y, ll modulo)
{
    x %= modulo;
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2, modulo) % modulo;
        ll yy = (y_2 * y_2) % modulo;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % modulo;
        }
    }
}

int solve()
{
    ll N ,K , M;
    cin >> N >> K >> M;
    if (M % BASE_NUM == 0){
        cout << 0 << endl;
    }else{
        ll shoulder = pow(K,N,BASE_NUM-1);
        cout << pow(M,shoulder,BASE_NUM) << endl;
    }
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}