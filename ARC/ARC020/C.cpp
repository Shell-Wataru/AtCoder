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

ll BASE_NUM = 1000000007;

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
    ll N;
    cin >> N;
    vector<pair<string,ll>> A(N);
    ll B;

    for (int i = 0; i < N; i++)
    {
        string a;
        ll l;
        cin >> a >> l;
        A[i] = {a,l};
    }
    cin >> B;
    ll ans = 0;
    for(auto p: A){
        ans = ans * pow(10,p.first.size() * p.second,B) % B;
        ans = (ans + (stoll(p.first) * pow_sum(pow(10,p.first.size(),B),p.second - 1,B)) % B) % B;
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}