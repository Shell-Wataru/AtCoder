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

struct block
{
  ll height;
  vector<ll> min_depth_counts = {0};
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<block> data(n);
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    block b;
    ll height = 0;
    ll min_height = 0;
    for (auto c : s)
    {
      if (c == '(')
      {
        height++;
      }
      else
      {
        height--;
        if (height == min_height)
        {
          b.min_depth_counts.back()++;
        }
        else if (height < min_height)
        {
          min_height = height;
          b.min_depth_counts.push_back(1);
        }
      }
    }
    b.height = height;
    data[i] = b;
  }
  vector<pair<ll, ll>> DP(1ll << n, {-1, 0});
  DP[0] = {0, 0};
  ll ans = 0;
  for (int i = 0; i < 1ll << n; i++)
  {
    // cout << i << endl;
    ll h = DP[i].first;
    if (h < 0)
    {
      continue;
    }
    for (int j = 0; j < n; j++)
    {
      if (!(i & 1ll << j))
      {
        ll min_depth = data[j].min_depth_counts.size() - 1;
        if (min_depth > h)
        {
          ll new_h = -1;
          ll new_patterns = DP[i].second + data[j].min_depth_counts[h];
          ans = max(ans, new_patterns);
          DP[i | 1ll << j] = max(DP[i | 1ll << j], {new_h, new_patterns});
        }
        else
        {
          ll new_h = data[j].height + h;
          ll new_patterns = DP[i].second;
          if (min_depth == h)
          {
            new_patterns += data[j].min_depth_counts[h];
          }
          ans = max(ans, new_patterns);
          DP[i | 1ll << j] = max(DP[i | 1ll << j], {new_h, new_patterns});
        }
      }
    }
  }
  cout << ans << endl;
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