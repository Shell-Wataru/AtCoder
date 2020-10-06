#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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

ll reverse(ll n, ll modulo)
{
    ll x, y;
    extGCD(n, modulo, x, y);
    return (x + ((abs(x / modulo) + 1) * modulo)) % modulo;
}

long long gcd(long long a, long long b)
{

    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

map<long long, long long> decomposite(long long N, map<long long, long long> &primes, long long next_p = 2)
{
    if (N == 1)
    {
        return primes;
    }

    while (next_p * next_p <= N)
    {
        if (N % next_p == 0)
        {
            primes[next_p] += 1;
            return decomposite(N / next_p, primes, next_p);
        }
        else
        {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}

class Number
{
public:
    map<ll, ll> decomposition;
    ll prime_value = 1;
    ll modulo;

    Number(ll n, ll _modulo)
    {
        modulo = _modulo;
        ll common = gcd(n, modulo);
        while(common != 1){
            n = n/common;
            map<ll, ll> common_decomposition;
            decomposite(common, common_decomposition);
            for(auto p: common_decomposition){
                decomposition[p.first] += p.second;
            }
            common = gcd(n, modulo);
        }
        prime_value = n % modulo;
    }

    ll value()
    {
        ll val = prime_value;
        for (auto p : decomposition)
        {
            val = val * pow(p.first, p.second, modulo) % modulo;
        }
        return val;
    }

    Number operator*(Number other)
    {
        Number new_number(*this);
        new_number.prime_value = new_number.prime_value * other.prime_value % modulo;
        for (auto p : other.decomposition)
        {
            new_number.decomposition[p.first] += p.second;
        }
        return new_number;
    }

    Number operator/(Number other)
    {
        Number new_number(*this);
        for (auto p : other.decomposition)
        {
            new_number.decomposition[p.first] -= p.second;
        }
        new_number.prime_value = new_number.prime_value * reverse(other.prime_value, modulo) % modulo;
        return new_number;
    }
};

int main()
{
    ll modulo = 1e9 + 7;
    Number n1(1,modulo);
    Number n2(1,modulo);
    Number n3 = n1 * n2;
    cout << n3.value() << endl;
    ll n = 4;
    Number combination(1,modulo);
    cout << combination.value() << endl;
    for (int i = 0; i < n; i++)
    {
        combination = combination * Number(n - i, modulo) / Number(i + 1, modulo);
        cout << combination.value() << endl;
    }
    return 0;
}