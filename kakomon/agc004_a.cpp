#define _USE_MATH_DEFINES
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

using namespace std;
using ll = long long;

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = numeric_limits<ll>::max();
    ans = min(ans, A * B * (C % 2));
    ans = min(ans, B * C * (A % 2));
    ans = min(ans, C * A * (B % 2));
    cout << ans << endl;
    return 0;
}