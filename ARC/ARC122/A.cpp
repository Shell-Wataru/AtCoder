#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

const long long BASE_NUM = 1000000007;
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
    vector<modint> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<modint> normal_patterns_use(N+1,0);
    vector<modint> normal_patterns_not_use(N+1,0);
    vector<modint> use_patterns_use(N+1,0);
    vector<modint> use_patterns_not_use(N+1,0);
    normal_patterns_not_use[0] = 1;
    use_patterns_use[0] = 1;
    for(int i = 0;i < N;i++){
        normal_patterns_use[i+1] += normal_patterns_not_use[i];
        normal_patterns_not_use[i+1] += normal_patterns_use[i] + normal_patterns_not_use[i];
        use_patterns_use[i+1] += use_patterns_not_use[i];
        use_patterns_not_use[i+1] += use_patterns_use[i] + use_patterns_not_use[i];
    }
    // for(int i = 0;i< N;i++){
    //     cout << normal_patterns_use[i] << endl;
    // }
    modint ans = A[0]*normal_patterns_not_use[N];
    for(int i = 1;i < N;i++){
        ans += A[i]* normal_patterns_not_use[i]*normal_patterns_not_use[N-i];
        ans -= A[i]* use_patterns_not_use[i]*use_patterns_not_use[N-i];
    }
    cout << ans << endl;
    return 0;
}