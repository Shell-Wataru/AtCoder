#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    // 整数の入力
    ll N, A, B, C;
    vector<ll> candidates(3);
    cin >> N >> candidates[0] >> candidates[1] >> candidates[2];
    sort(candidates.begin(), candidates.end());
    A = candidates[1];
    B = candidates[2];
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < 10000; i++)
    {
        ll remain = N - A * i;
        if (remain % gcd(B, C) != 0)
        {
            continue;
        }
        else
        {
            ll x, y;
            extGCD(B / gcd(B, C), C / gcd(B, C), x, y);
            ll j = remain / gcd(B, C) * x;
            ll k = remain / gcd(B, C) * y;
        }
    }
    return 0;
}