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

int value(char c)
{
  int n = c - '0';
  if (n < 10)
  {
    return n;
  }
  else
  {
    return n - 7;
  }
}
int main()
{
  // 整数の入力
  ll K;
  string S;
  cin >> S;
  cin >> K;
  vector<bool> max_using_numbers(16, false);
  vector<vector<modint>> not_max_patterns(S.length() + 1, vector<modint>(K + 1, modint(0)));
  for (int i = 1; i <= S.length(); i++)
  {
    not_max_patterns[i][0] = 1;
  }
  for (int i = 1; i <= S.length(); i++)
  {
    ll before_max_using_patterns = 0;
    for (int j = 0; j < 16; j++)
    {
      if (max_using_numbers[j])
      {
        before_max_using_patterns++;
      }
    }
    // cout << "++" << endl;
    for (int j = 0; j < value(S[i - 1]); j++)
    {
      if (i != 1 || j > 0)
      {
        // cout << j << endl;
        if (max_using_numbers[j])
        {
          // cout << "o" << endl;
          not_max_patterns[i][before_max_using_patterns] += 1;
        }
        else
        {
          // cout << "x" << endl;
          not_max_patterns[i][before_max_using_patterns + 1] += 1;
        }
      }
    }

    for (int j = 1; j <= K; j++)
    {
      if (j == 1){
        not_max_patterns[i][j] += not_max_patterns[i - 1][j] * j + not_max_patterns[i - 1][j - 1] * (16 - j);
      }else{
        not_max_patterns[i][j] += not_max_patterns[i - 1][j] * j + not_max_patterns[i - 1][j - 1] * (16 - j + 1);
      }

    }

    max_using_numbers[value(S[i - 1])] = true;
  }
  ll max_using_patterns = 0;
  for (int j = 0; j < 16; j++)
  {
    if (max_using_numbers[j])
    {
      max_using_patterns++;
    }
  }
  // for (int i = 0; i <= S.length(); i++)
  // {
  //   for (int j = 0; j <= K; j++)
  //   {
  //     cout << not_max_patterns[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  if (max_using_patterns == K)
  {
    cout << not_max_patterns[S.length()][K] + 1 << endl;
  }
  else
  {
    cout << not_max_patterns[S.length()][K] << endl;
  }
  return 0;
}