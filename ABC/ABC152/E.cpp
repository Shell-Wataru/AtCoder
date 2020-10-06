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

ll pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2) % BASE_NUM;
        ll yy = (y_2 * y_2) % BASE_NUM;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % BASE_NUM;
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

class LCM
{
public:
    map<ll, ll> decomposition;

    LCM(ll n)
    {
        decomposite(n,decomposition);
    }

    ll value()
    {
        ll val = 1;
        for (auto p : decomposition)
        {
            val = val * pow(p.first, p.second) % BASE_NUM;
        }
        return val;
    }

    void product(ll n)
    {
        map<ll,ll> other_decomposition;
        decomposite(n,other_decomposition);
        for (auto p : other_decomposition)
        {
            decomposition[p.first] = max(p.second,decomposition[p.first]);
        }
    }
};

//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
vector<ll> inverse_array(ll n){
    vector<ll> inverse(n,-1);
    inverse[1] = 1;
    for(int i = 2;i<n;i++){
        inverse[i] = BASE_NUM - inverse[BASE_NUM % i] * (BASE_NUM/i) % BASE_NUM;
    }
    return inverse;
}

int main()
{
    // 整数の入力
    ll N,K;
    vector<ll> A;
    cin >> N;
    vector<ll> inverses = inverse_array(1000001);
    LCM lcm(1);
    for(int i = 0;i< N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
        lcm.product(a);
    }

    ll lcm_value = lcm.value();
    // cout << all_lcm_value << endl;
    ll sum_b = 0;
    for(int i = 0;i< N;i++){
        ll b = lcm_value * inverses[A[i]] % BASE_NUM;
        // cout << b << endl;
        sum_b = (sum_b + b) % BASE_NUM;
    }
    cout << sum_b << endl;;
    return 0;
}
