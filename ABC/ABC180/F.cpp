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
template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}
struct fast_ios
{
    fast_ios()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

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
    // 整数の入力
    ll N, M ,L;
    cin >> N >> M >> L;
    //
    auto DP = make_vec(N+1,M+1,L+1,2,N+1,modint(0));
    for (size_t i = 0; i <= N ; i++)
    {
            for (size_t j = 0; j <= M ; j++)
    {
            for (size_t k = 0; k <= L ; k++)
    {

            for (size_t i = 0; i <= N ; i++)
    {

    }

    }

    }

    }

    return 0;
}