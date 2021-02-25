#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll S, P;
    cin >> S >> P;
    bool can = false;
    for (ll i = 1; i * i <= P; i++)
    {
        if (P % i == 0 && (i + P / i) == S)
        {
            can = true;
            break;
        }
    }
    if (can)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}