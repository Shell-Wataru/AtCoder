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
namespace mp = boost::multiprecision;

const long long BASE_NUM = 1000000007;
// https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
//  https://ei1333.github.io/luzhiled/snippets/math/combination.html
template <int mod>
struct ModInt
{
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p)
    {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const
    {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};
using modint = ModInt<998244353>;

template <typename T>
struct Combination
{
    vector<T> _fact, _rfact, _inv;

    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1)
    {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for (int i = 1; i <= sz; i++)
            _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for (int i = sz - 1; i >= 0; i--)
            _rfact[i] = _rfact[i + 1] * (i + 1);
        for (int i = 1; i <= sz; i++)
            _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const
    {
        if (r < 0 || n < r)
            return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const
    {
        if (q < 0 || p < q)
            return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const
    {
        if (n < 0 || r < 0)
            return (0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};

int main()
{
    // 整数の入力
    ll L;
    cin >> L;
    vector<ll> A(L);
    for (int i = 0; i < L; i++)
    {
        cin >> A[i];
    }
    vector<ll> DP_before_2start(L + 1,numeric_limits<ll>::max()/2);
    vector<ll> DP_before_1start(L + 1,numeric_limits<ll>::max()/2);
    vector<ll> DP_before_1end(L + 1,numeric_limits<ll>::max()/2);
    vector<ll> DP_before_2end(L + 1,numeric_limits<ll>::max()/2);
    vector<ll> DP_after_2end(L + 1,numeric_limits<ll>::max()/2);
    DP_before_2start[0] = 0;
    for (int i = 0; i < L; i++)
    {
        DP_before_2start[i + 1] = DP_before_2start[i] + A[i];
        if (A[i]== 0){
            DP_before_1start[i + 1] = min(DP_before_1start[i + 1], DP_before_2start[i] + 2);
            DP_before_1start[i + 1] = min(DP_before_1start[i + 1], DP_before_1start[i] + 2);
        }else{
            DP_before_1start[i + 1] = min(DP_before_1start[i + 1], DP_before_2start[i] + A[i] % 2);
            DP_before_1start[i + 1] = min(DP_before_1start[i + 1], DP_before_1start[i] + A[i] % 2);
        }

        DP_before_1end[i + 1] = min(DP_before_1end[i + 1], DP_before_2start[i] + (A[i] + 1) % 2);
        DP_before_1end[i + 1] = min(DP_before_1end[i + 1], DP_before_1start[i] + (A[i] + 1) % 2);
        DP_before_1end[i + 1] = min(DP_before_1end[i + 1], DP_before_1end[i] + (A[i] + 1) % 2);

        if (A[i]== 0){
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_2start[i] + 2);
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_1start[i] + 2);
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_1end[i] + 2);
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_2end[i] + 2);
        }else{
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_2start[i] + (A[i]) % 2);
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_1start[i] + (A[i]) % 2);
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_1end[i] + (A[i]) % 2);
            DP_before_2end[i + 1] = min(DP_before_2end[i + 1], DP_before_2end[i] + (A[i]) % 2);
        }
        DP_after_2end[i + 1] = min(DP_after_2end[i + 1], DP_before_2start[i] + A[i]);
        DP_after_2end[i + 1] = min(DP_after_2end[i + 1], DP_before_1start[i] + A[i]);
        DP_after_2end[i + 1] = min(DP_after_2end[i + 1], DP_before_1end[i] + A[i]);
        DP_after_2end[i + 1] = min(DP_after_2end[i + 1], DP_before_2end[i] + A[i]);
        DP_after_2end[i + 1] = min(DP_after_2end[i + 1], DP_after_2end[i] + A[i]);
    }
    ll ans = numeric_limits<ll>::max();
    ans = min(ans,DP_before_2start[L]);
    ans = min(ans,DP_before_1start[L]);
    ans = min(ans,DP_before_1end[L]);
    ans = min(ans,DP_before_2end[L]);
    ans = min(ans,DP_after_2end[L]);
    cout << ans << endl;
    return 0;
}