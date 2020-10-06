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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;
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

int main()
{
  ll N, K;
  string S;
  cin >> N >> K >> S;
  vector<vector<vector<modint>>> DP(N + 1, vector<vector<modint>>(K + 1, vector<modint>(K + 1, 0)));
  DP[0][0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == '1')
    {
      for (int j = 0; j <= K; j++)
      {
        for (int k = 0; k < K; k++)
        {
          DP[i + 1][max(j - 1, 0)][k + 1] += DP[i][j][k];
        }
      }
    }
    else if (S[i] == '0')
    {
      for (int j = 0; j < K; j++)
      {
        for (int k = 0; k <= K; k++)
        {
          DP[i + 1][j + 1][max(k - 1, 0)] += DP[i][j][k];
        }
      }
    }
    else
    {
      for (int j = 0; j <= K; j++)
      {
        for (int k = 0; k < K; k++)
        {
          DP[i + 1][max(j - 1, 0)][k + 1] += DP[i][j][k];
        }
      }
      for (int j = 0; j < K; j++)
      {
        for (int k = 0; k <= K; k++)
        {
          DP[i + 1][j + 1][max(k - 1, 0)] += DP[i][j][k];
        }
      }
    }
  }
  modint ans = 0;
  for (int j = 0; j <= K; j++)
  {
    for (int k = 0; k <= K; k++)
    {
      ans += DP[N][j][k];
    }
  }
  // for (int i = 0; i <= N; i++)
  // {
  //   for (int j = -K; j <= K; j++)
  //   {
  //     cout << DP[i][j + K] << ",";
  //   }
  //   cout << endl;
  // }
  cout << ans << endl;
  return 0;
}