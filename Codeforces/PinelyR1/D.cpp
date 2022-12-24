#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

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

int naive(ll n,ll k){
  ll ans = 0;
  for(int i = 0;i < 1ll<<n;i++){
    for(int j = 0;j < 1ll<<n;j++){
      if (__builtin_popcountll(i)+__builtin_popcountll(j)- __builtin_popcountll(i+j) == k){
        ans++;
      }
    }
  }
  return ans;
}

int solve()
{
  ll n, k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  Combination<modint> C(2000000);
  modint ans = 0;
  modint one = 1;
  modint two = 2;
  modint three = 3;
  if (k == 0){
    cout << three.pow(n) << endl;
    return 0;
  }
  for(int i = 1;i <= k;i++){
    ll zeroone = i;
    ll oneone = k-i;
    ll zeros = n+1 - k - i;
    // cout << "zeroone:" << zeroone << endl;
    // cout << "oneone:" << oneone << endl;
    // cout << "zeros:" << zeros << endl;
    // cout << C.C(zeroone+oneone-1,zeroone-1) << endl;
    // cout << C.C(zeros+zeroone,zeroone) << endl;
    // 先頭が0
    // cout << "head0:" << C.C(zeroone+oneone-1,zeroone-1)*C.C(zeros-1+zeroone,zeroone) << endl;
    ans += C.C(zeroone+oneone-1,zeroone-1)*C.C(zeros-1+zeroone,zeroone)*three.pow(oneone)*three.pow(zeros-1);
    // 先頭が1
    // cout << "head1:" << C.C(zeroone+oneone-1,zeroone-1)*C.C(zeros+zeroone-1,zeroone-1) << endl;
    ans += C.C(zeroone+oneone-1,zeroone-1)*C.C(zeros+zeroone-1,zeroone-1)*three.pow(oneone)*three.pow(zeros);
  }
  cout << ans << endl;
  // cout << naive(n,k) << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
