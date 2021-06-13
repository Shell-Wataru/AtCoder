#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

const long long BASE_NUM = 998244353;
//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
// https://ei1333.github.io/luzhiled/snippets/math/combination.html
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
using modint = ModInt< BASE_NUM >;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  vector<modint> RuisekiWa(N+1);
  modint two = 2;
  for(int i = 0;i < N;i++){
    RuisekiWa[i+1] = RuisekiWa[i] + two.pow(i) * A[i];
  }
  // for(int i = 0;i <= N;i++){
  //   cout << RuisekiWa[i] << endl;;
  // }
  modint ans = 0;
  for(int i = 0;i < N;i++){
    // cout << A[i] << ":" << (RuisekiWa[N] - RuisekiWa[i+1])/two.pow(i+1) * A[i] << endl;
    ans += (RuisekiWa[N] - RuisekiWa[i+1])/two.pow(i+1) * A[i] + A[i]*A[i];
  }
  cout << ans << endl;
  return 0;
}