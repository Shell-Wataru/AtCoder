#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;


ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2);
        ll yy = y_2 * y_2;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return yy * x;
        }
    }
}

int main()
{
    string N;
    cin >> N;
    ll one_count = 0;
    ll ans = 0;
    ll remain_size = N.size();
    for(auto c:N){
        remain_size--;
        ll n = c - '0';
        if (n == 0){
            continue;
        }else if (n == 1){
            ans += remain_size * my_pow(10,remain_size - 1);
            ans += one_count * my_pow(10,remain_size);
            one_count++;
        }else{
            ans += (n-1)*remain_size * my_pow(10,remain_size - 1);
            ans += (n-1)*one_count * my_pow(10,remain_size);
            ans += remain_size * my_pow(10,remain_size - 1);
            ans += (one_count+1) * my_pow(10,remain_size);
        }
    }
    ans += one_count;
    cout << ans << endl;
    return 0;
}