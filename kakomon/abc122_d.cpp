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

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
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

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< 1000000007 >;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<map<string, modint>> DP(2);
    string chars = "AGCT";
    string bad_a = "AGC";
    string bad_b = "GAC";
    string bad_c = "ACG";
    for (auto a : chars)
    {
        for (auto b : chars)
        {
            for (auto c : chars)
            {
                string base;
                base += a;
                base += b;
                base += c;
                if (base != bad_a && base != bad_b && base != bad_c)
                {
                    DP[0][base] += 1;
                }
            }
        }
    }
    for (int i = 4; i <= N; i++)
    {
        ll current_index = i % 2;
        ll next_index = (i + 1) % 2;
        // cout << current_index << " " << next_index << endl;
        DP[next_index].clear();
        for (auto &p : DP[current_index])
        {
            for (auto &a : chars)
            {
                string base = p.first.substr(1) + a;
                if (base != bad_a &&
                    base != bad_b &&
                    base != bad_c &&
                    !(p.first.substr(0,2) == "AG" && a == 'C') &&
                    !(p.first[0] == 'A' &&  p.first[2] == 'G' && a == 'C'))
                {
                    DP[next_index][base] += p.second;
                }
            }
        }
    }

    modint ans = 0;
    for (auto &p : DP[(N + 1) % 2])
    {
        ans += p.second;
    }
    cout << ans << endl;
    return 0;
}