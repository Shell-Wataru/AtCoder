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
#include <stack>

using namespace std;
using ll = long long;

const long long BASE_NUM = 998244353;
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
using modint = ModInt<BASE_NUM>;

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

using modint = ModInt<BASE_NUM>;

int main()
{
    // 整数の入力
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<modint>> DP(n + 1, vector<modint>(1ll << 11, 0));
    ll start_mask = 0;
    ll end_mask = 0;
    for(int i = -d;i < 0;i++){
        start_mask |= 1ll<<(5+i);
        end_mask |= 1ll<<(5+i);
    }
    // for(int i = 0;i <=d;i++){
    //     end_mask |= 1ll<<(5+i);
    // }
    DP[0][start_mask] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1ll << 11; j++)
        {
            if (a[i] == -2)
            {
                for (int k = -d; k <= d; k++)
                {
                    if (j & 1ll<<(k+5) ){
                        continue;
                    }else{
                        ll next_j = j | 1ll<<(k+5);
                        if (next_j & 1ll<<(-d+5)){
                            next_j = next_j & ~(1ll<<(-d+5));
                            next_j >>= 1;
                            DP[i+1][next_j] += DP[i][j];
                        }
                    }
                }
            }
            else
            {
                ll k = a[i] - i;
                if (j & 1ll<<(k+5) ){
                    continue;
                }else{
                    ll next_j = j | 1ll<<(k+5);
                    if (next_j & 1ll<<(-d+5)){
                        next_j = next_j & ~(1ll<<(-d+5));
                        next_j >>= 1;
                        DP[i+1][next_j] += DP[i][j];
                    }
                }
            }
        }
    }
    // for(int j = 0;j <= n;j++){
    //     cout << j << "=>" << endl;
    //     for(int i = 0;i < 1ll<<11;i++){
    //         if (DP[j][i] != 0){
    //             cout << i << ":" << DP[j][i] << endl;
    //         }

    //     }
    // }
    cout << DP[n][end_mask] << endl;
    return 0;
}
