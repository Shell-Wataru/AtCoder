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
#include <set>
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

struct ArbitraryModInt
{

    int x;

    ArbitraryModInt() : x(0) {}

    ArbitraryModInt(int64_t y) : x(y >= 0 ? y % mod() : (mod() - (-y) % mod()) % mod()) {}

    static int &mod()
    {
        static int mod = 0;
        return mod;
    }

    static int set_mod(int md)
    {
        mod() = md;
        return 0;
    }

    ArbitraryModInt &operator+=(const ArbitraryModInt &p)
    {
        if ((x += p.x) >= mod())
            x -= mod();
        return *this;
    }

    ArbitraryModInt &operator-=(const ArbitraryModInt &p)
    {
        if ((x += mod() - p.x) >= mod())
            x -= mod();
        return *this;
    }

    ArbitraryModInt &operator*=(const ArbitraryModInt &p)
    {
        unsigned long long a = (unsigned long long)x * p.x;
        unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
        asm("divl %4; \n\t"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(mod()));
        x = m;
        return *this;
    }

    ArbitraryModInt &operator/=(const ArbitraryModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

    ArbitraryModInt operator+(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) += p; }

    ArbitraryModInt operator-(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) -= p; }

    ArbitraryModInt operator*(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) *= p; }

    ArbitraryModInt operator/(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) /= p; }

    bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

    bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

    ArbitraryModInt inverse() const
    {
        int a = x, b = mod(), u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ArbitraryModInt(u);
    }

    ArbitraryModInt pow(int64_t n) const
    {
        ArbitraryModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ArbitraryModInt &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ArbitraryModInt &a)
    {
        int64_t t;
        is >> t;
        a = ArbitraryModInt(t);
        return (is);
    }
};

using modint = ArbitraryModInt;
int main()
{
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<ll> AB(N + 1);
    vector<ll> BC(N + 1);
    vector<ll> CA(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] == 'A' && S[i + 1] == 'B')
        {
            AB[i + 1]++;
        }
        else if (S[i] == 'B' && S[i + 1] == 'A')
        {
            AB[i + 1]++;
        }
        else if (S[i] == 'B' && S[i + 1] == 'C')
        {
            BC[i + 1]++;
        }
        else if (S[i] == 'C' && S[i + 1] == 'B')
        {
            BC[i + 1]++;
        }
        else if (S[i] == 'C' && S[i + 1] == 'A')
        {
            CA[i + 1]++;
        }
        else if (S[i] == 'A' && S[i + 1] == 'C')
        {
            CA[i + 1]++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        AB[i] += AB[i - 1];
        BC[i] += BC[i - 1];
        CA[i] += CA[i - 1];
    }
    for (int i = 0; i < Q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        // cout << "ab:" << (AB[r] - AB[l] + 1) / 2 << endl;
        // cout << "bc:" << (BC[r] - BC[l] + 1) / 2 << endl;
        // cout << "ca:" << (CA[r] - CA[l] + 1) / 2 << endl;
        ll ans = (AB[r] - AB[l] + 1) / 2 + (BC[r] - BC[l] + 1) / 2 + (CA[r] - CA[l] + 1) / 2;
        if ((AB[r] - AB[l]) % 2 + (BC[r] - BC[l]) % 2 + (CA[r] - CA[l]) % 2 == 3)
        {
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
