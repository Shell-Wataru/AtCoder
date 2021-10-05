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

int main()
{
    // 整数の入力
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b)
    {
        cout << c << endl;
    }
    else if (b == c)
    {
        cout << a << endl;
    }
    else if (c == a)
    {
        cout << b << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}