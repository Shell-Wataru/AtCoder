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

int solve()
{
    ll a,b,c;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    ll base = gcd(gcd(a,b),c);
    cout << a/base - 1 + b/base - 1 + c/base - 1 << endl;
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}