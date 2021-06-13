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

int main()
{
  // 整数の入力
  ll P, a, b;
  cin >> P >> a >> b;
  ArbitraryModInt::set_mod(P);
  vector<ll> number_index(P + 1);
  ArbitraryModInt current = 1;
  // cout << current << endl;
  ll a_period = 0;
  ll b_period = 0;
  for (int i = 0; i < P; i++)
  {
    a_period++;
    current *= a;
    if (current == 1){
      break;
    }
  }
  for (int i = 0; i < P; i++)
  {
    b_period++;
    current *= b;
    if (current == 1){
      break;
    }
  }
  if
  return 0;
}