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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

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

long long combination(long long n, long long m)
{
    long long value = 1;
    m = min(m, n - m);
    for (long long i = 0; i < m; i++)
    {
        value = (value * (n - i)) % BASE_NUM;
    }

    for (long long i = 1; i <= m; i++)
    {
        long long x, y, reverse;
        extGCD(i, BASE_NUM, x, y);
        reverse = (x + ((abs(x / BASE_NUM) + 1) * BASE_NUM)) % BASE_NUM;
        value = (value * reverse) % BASE_NUM;
    }
    return value;
}

ll pow(ll x, ll y, ll modulo)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2, modulo) % modulo;
        ll yy = (y_2 * y_2) % modulo;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % modulo;
        }
    }
}

int main()
{
    // 整数の入力
    ll N;
    vector<ll> C;
    vector<ll> SumC;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll c;
        cin >> c;
        C.push_back(c);
    }
    sort(C.begin(), C.end());

    ll count = 0;
    ll cost = 0;
    for (int i = 0; i < N; i++)
    {
        count += C[i] * (N - i) * pow(2, N - 1, BASE_NUM) % BASE_NUM;
    }
    cout << count * pow(2, N, BASE_NUM) % BASE_NUM << endl;
    return 0;
}