#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

const long long BASE_NUM = 998244353;
const ll INF = numeric_limits<ll>::max();
struct LazySegmentTree
{
private:
    ll n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<ll> v)
    {
        ll sz = (ll)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);
        lazyFlag.resize(2 * n - 1, false);

        for (ll i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (ll i = n - 2; i >= 0; i--)
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void lazyEvaluate(ll k, ll l, ll r)
    {
        if (lazyFlag[k])
        {
            node[k] = lazy[k] + node[k];
            if (r - l > 1)
            {
                lazy[k * 2 + 1] += lazy[k];
                lazy[k * 2 + 2] += lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
            lazy[k] = 0;
        }
    }

    void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] = lazy[k] + x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else
        {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll find(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return INF;
        if (a <= l && r <= b)
            return node[k];
        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    int find_rightest_sub(int a, int b,ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (node[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn -1
            return - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != - 1) {  // 右の部分木を見て -1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
};

//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
// https://ei1333.github.io/luzhiled/snippets/math/combination.html
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

int solve()
{

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(M);
    for (int i = 0; i < N; i++)
    {
        ll a;
        scanf("%lld", &A[i]);
    }
    LazySegmentTree seg(A);

    for (int i = 0; i < M; i++)
    {
        scanf("%lld", &B[i]);
    }
    modint ans = 1;
    ll last_rightest_nxt = -1;
    ll last_rightest = N;
    for (int i = M - 1; i >= 1; i--)
    {
        ll rightest = seg.find_rightest_sub(0,N,B[i]);
        ll rightest_next = seg.find_rightest_sub(0,N,B[i] - 1);
        // cout << rightest << rightest_next << endl;
        last_rightest = rightest;
        last_rightest_nxt = rightest_next;
        ans *= (rightest - rightest_next);
    }
    cout << last_rightest << endl;
    cout << last_rightest_nxt << endl;
    if (last_rightest_nxt == -1){
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
    // cout << ans << endl;
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