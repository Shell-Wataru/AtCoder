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

ll combination(ll n, ll m)
{
    ll ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll N, P;
    cin >> N >> P;
    ll odds = 0;
    ll evens = 0;
    for (ll i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        if (a % 2 == 0)
        {
            evens++;
        }
        else
        {
            odds++;
        }
    }
    if (P % 2 == 0)
    {
        ll odd_patterns = 0;
        for (ll i = 0; i <= odds; i += 2)
        {
            odd_patterns += combination(odds, i);
        }
        cout << odd_patterns * (1ll << evens) << endl;
    }
    else
    {
        ll odd_patterns = 0;
        for (ll i = 1; i <= odds; i += 2)
        {
            odd_patterns += combination(odds, i);
        }
        cout << odd_patterns * (1ll << evens) << endl;
    }

    return 0;
}