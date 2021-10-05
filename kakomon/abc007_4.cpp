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

ll pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2);
        ll yy = (y_2 * y_2);
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x);
        }
    }
}

ll count(ll A)
{
    ll oks = 0;
    string a = to_string(A);
    ll n = a.size();
    ll max_count = 0;

    bool broke = false;
    for (int i = 0; i < n; i++)
    {
        ll cur = a[i] - '0';
        // cout << cur << endl;
        for (int j = 0; j < cur; j++)
        {
            if (j != 4 && j != 9){

                oks +=  pow(8,n-i-1);
            }
        }
        if (cur == 4 || cur == 9){
            broke = true;
            break;
        }
    }
    if (!broke){
        oks++;
    }
    // cout << A << ":" << oks << endl;
    return A + 1 - oks;
}
int main()
{
    // 整数の入力
    ll A, B;
    cin >> A >> B;
    cout << count(B) - count(A - 1) << endl;
    return 0;
}