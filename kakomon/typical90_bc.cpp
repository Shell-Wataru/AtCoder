#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;

struct ArbitraryModInt {

  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y) : x(y >= 0 ? y % mod() : (mod() - (-y) % mod()) % mod()) {}

  static int &mod() {
    static int mod = 0;
    return mod;
  }

  static int set_mod(int md) {
    mod() = md;
    return 0;
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if((x += p.x) >= mod()) x -= mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if((x += mod() - p.x) >= mod()) x -= mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long) x * p.x;
    unsigned xh = (unsigned) (a >> 32), xl = (unsigned) a, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
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

  ArbitraryModInt inverse() const {
    int a = x, b = mod(), u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};

int main()
{
  // 整数の入力
  ll N,P,Q;
  cin >> N >> P >> Q;
  ArbitraryModInt::set_mod(P);
  vector<ArbitraryModInt> A(N);
  for(int i = 0;i < N;i++){
      cin >> A[i];
  }
  ll ans = 0;
  for(int i1 = 0;i1 < N;i1++){
      for(int i2 = i1+1;i2 < N;i2++){
          for(int i3 = i2+1;i3 < N;i3++){
              for(int i4 = i3+1;i4 < N;i4++){
                  for(int i5 = i4+1;i5 < N;i5++){
                      if ((A[i1] * A[i2] *A[i3] *A[i4] *A[i5]).x == Q){
                          ans++;
                      }
                  }
              }
          }
      }
  }
  cout << ans << endl;
  return 0;
}