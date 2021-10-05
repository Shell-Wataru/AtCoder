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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll S;
    ll X1 = 0;
    ll Y1 = 0;
    cin >> S;
    ll base = 1000000000ll;
    ll X2 = base;
    ll Y3 = (S+ base - 1)/base;
    ll X3 = 1;
    ll Y2 = (X2*Y3 - S)%base;
    // cout << X2*Y3 - X3*Y2 << endl;
    cout << X1 << "  " << Y1 << " " << X2 << " " << Y2 << " " << X3 << " " << Y3 << endl;
    return 0;
}