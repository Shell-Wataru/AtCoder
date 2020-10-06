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

class RationalNumber
{
public:
    ll p = 1;
    ll q = 1;

    RationalNumber(ll p, ll q) : p(p),q(q)
    {
        ll common = gcd(p,q);
        p = p/common;
        q = q/common;
    }

    ll value()
    {
        return p/q;
    }

    RationalNumber operator*(RationalNumber other)
    {
        return RationalNumber(p * other.p, q * other.q);
    }

    RationalNumber operator/(RationalNumber other)
    {
        return RationalNumber(p * other.q, q * other.p);
    }
};

int main()
{
    RationalNumber n1(1,1);
    RationalNumber n2(3,1);
    RationalNumber n3 = n1 * n2;
    cout << n3.value() << endl;
    ll n = 4;
    RationalNumber combination(1,1);
    cout << combination.value() << endl;
    for (int i = 0; i < n; i++)
    {
        combination = combination * RationalNumber(n - i, 1) / RationalNumber(i + 1, 1);
        cout << combination.value() << endl;
    }
    return 0;
}