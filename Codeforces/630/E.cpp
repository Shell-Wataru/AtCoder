#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

ll BASE_NUM = 998224353;

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

int solve()
{
    ll L,R,n,m;
    cin >> n >> m >> L >> R;
    ll odd_count,even_count;
    if (L % 2 == 1){
        odd_count = (R - L + 1 + 1)/2;
        even_count = (R - L + 1) - odd_count;
    }else{
        even_count = (R - L + 1 + 1)/2;
        odd_count = (R - L + 1) - even_count;
    }
    if(n* m % 2 == 1){
        cout << pow(R - L + 1, n * m, BASE_NUM) << endl;
    }else{
        ll odd = 0;
        ll even = 1;
        for(int i = 0;i < n * m;i++){
            ll new_odd = ((odd * even_count  % BASE_NUM) + (even * odd_count % BASE_NUM)) % BASE_NUM;
            ll new_even = ((odd * odd_count % BASE_NUM) + (even * even_count % BASE_NUM)) % BASE_NUM;
            odd = new_odd;
            even = new_even;
        }
        cout << even << endl;
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}