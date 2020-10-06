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
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

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

using modint = ModInt<1000000007>;

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

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  map<pair<ll, ll>, ll> counts;
  ll zerozero = 0;
  modint total = 1;
  for (int i = 0; i < N; i++)
  {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if (a == 0 && b == 0){
      zerozero++;
      continue;
    }else if(a == 0){
      a = 0;
      b = 1;
    }else if(b == 0){
      a = 1;
      b = 0;
    }else{
      ll gc = gcd(a, b);
      a = a / gc;
      b = b / gc;
    }

    if (a < 0)
    {
      a *= -1;
      b *= -1;
    }
    counts[{a, b}]++;
  }
  vector<pair<pair<ll, ll>, ll>> iter(counts.begin(), counts.end());
  map<pair<ll, ll>, ll> used;
  for (int i = 0; i < iter.size(); i++)
  {
    modint two = 2;
    auto p = iter[i];
    // cout << p.first.first << "," << p.first.second << ":" << p.second << endl;
    ll inv_a = -p.first.second;
    ll inv_b = p.first.first;
    if (inv_a < 0)
    {
      inv_a *= -1;
      inv_b *= -1;
    }
    modint use_inv = total * (two.pow(used[{inv_a, inv_b}]) - 1) / two.pow(used[{inv_a, inv_b}]);
    modint not_use_inv = total * two.pow(p.second) / two.pow(used[{inv_a, inv_b}]);
    // cout << use_inv << " " << not_use_inv << endl;
    total = use_inv + not_use_inv;
    used[p.first] = p.second;
  }
  cout << total + zerozero - 1 << endl;
  return 0;
}
