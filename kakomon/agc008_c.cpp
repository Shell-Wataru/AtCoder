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
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = O + 2 * (I / 2) + 2 * (J / 2) + 2 * (L / 2);
    ll remain = I % 2 + J % 2 + L % 2;
    if (remain == 3)
    {
        ans += 3;
    }
    else if (remain == 2)
    {
        if ((I % 2 + J % 2 == 2 && L > 0) ||
            (J % 2 + L % 2 == 2 && I > 0) ||
            (L % 2 + I % 2 == 2 && J > 0))
        {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}