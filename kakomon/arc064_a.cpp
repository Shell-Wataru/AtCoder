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
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N + 1);
    for (size_t i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            ans += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    cout << ans << endl;
    return 0;
}