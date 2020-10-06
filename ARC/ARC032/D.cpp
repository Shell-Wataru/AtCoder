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

using modint = ModInt<1000000007>;

ll count(vector<vector<ll>> &G, ll x_from, ll x_to, ll y_from, ll y_to)
{
  // cout << "X:" << x << ",Y:" << y << ",d:" << d << "=" << G[x + d][y + d] - G[x][y + d] - G[x + d][y] + G[x][y] << endl;
  x_to = min((ll)G.size() - 1ll, x_to);
  y_to = min((ll)G[0].size() - 1ll, y_to);
  return G[x_to][y_to] - G[x_from][y_to] - G[x_to][y_from] + G[x_from][y_from];
}
int min_diff(vector<vector<ll>> &G, ll K, ll x, ll y, ll l, ll r)
{
  if (l + 1 == r)
  {
    return r;
  }

  ll center = (l + r) / 2;
  if (count(G, x, x + center, y, y + center) < K)
  {
    return min_diff(G, K, x, y, center, r);
  }
  else
  {
    return min_diff(G, K, x, y, l, center);
  }
}

int main()
{
  // 整数の入力
  ll N, K;
  cin >> N >> K;
  vector<vector<ll>> G(3002, vector<ll>(3002, 0));
  for (int i = 0; i < N; i++)
  {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    x++;
    y++;
    G[x][y]++;
  }
  // cout << "ss" << endl;
  for (int i = 1; i <= 3001; i++)
  {
    for (int j = 1; j <= 3001; j++)
    {
      G[i][j] += G[i][j - 1] + G[i - 1][j] - G[i - 1][j - 1];
    }
  }
  // cout << "aaa" << endl;
  ll min_d = 1000000000;
  modint min_count = 0;
  Combination<modint> combinator(N);
  for (int i = 0; i <= 3000; i++)
  {
    for (int j = 0; j <= 3000; j++)
    {
      // cout << "!!" << endl;
      ll max_diff = 3000 - min(i, j) + 2;
      ll diff = min_diff(G, K, i, j, 0, max_diff);
      // cout << "i" << i << "j"  << j << ": "<< diff << endl;
      // cout << count(G,i,j,10) << endl;
      ll total_count = count(G, i, i + diff, j, j + diff);
      ll row_count = count(G, i, i + 1, j, j + diff);
      ll column_count = count(G, i, i + diff, j, j + 1);
      ll d_count = count(G, i + 1, i + diff, j + 1, j + diff);
      if (diff == max_diff)
      {
        continue;
      }
      else if (diff < min_d)
      {
        min_d = diff;
        min_count = combinator.C(total_count, K) - combinator.C(total_count - row_count,K) - combinator.C(total_count - column_count,K) + combinator.C(d_count,K);
        // cout << "i" << i << "j" << j << ": " << diff << endl;
      }
      else if (diff == min_d)
      {
        min_count += combinator.C(total_count, K) - combinator.C(total_count - row_count,K) - combinator.C(total_count - column_count,K) + combinator.C(d_count,K);
        // cout << "i" << i << "j" << j << ": " << diff << endl;
      }
    }
  }
  cout << min_d - 1 << endl;
  cout << min_count << endl;
  return 0;
}