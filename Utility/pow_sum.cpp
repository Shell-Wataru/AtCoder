#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll pow(ll x, ll y, ll modulo)
{
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

ll pow_sum(ll x,ll y, ll modulo){
    if (y == 0){
        return 1LL % modulo;
    }else{


        if (y % 2 == 0)
        {
            ll m = y/2;
            ll y_2 = pow_sum(x, m - 1, modulo) % modulo;
            ll yy = ((y_2 * pow(x,m ,modulo) % modulo + y_2) % modulo + pow(x,2 *m, modulo)) % modulo;
            return yy;
        }
        else
        {
            ll m = y/2;
            ll y_2 = pow_sum(x, m, modulo) % modulo;
            ll yy = (y_2 * pow(x,m + 1,modulo) % modulo + y_2) % modulo;
            return yy;
        }
    }
}

int main()
{
    ll modulo = 1e9 + 7;
    cout << pow(2,5,modulo) << endl;
    cout << pow_sum(1000,1,modulo) << endl;
    cout << pow_sum(1000,2,modulo) << endl;
    cout << pow_sum(1000,3,modulo) << endl;
    cout << pow_sum(1000,4,modulo) << endl;
    return 0;
}