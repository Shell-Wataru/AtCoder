#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

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

template< typename T >
struct Combination {
  ll mod;
  vector< T > _fact;

  Combination(): mod(T::get_mod()), _fact(mod) {
    _fact[0] = 1;
    for(int i = 1; i <= mod; i++) _fact[i] = _fact[i - 1] * i;
  }

  // 蟻本262ページ
  inline pair<T,ll> fact(int k) const {
    if (k == 0){
      return {1,0};
    }
    pair<T,ll> res = fact(k/mod);
    if (k/mod % 2 != 0){
      return {-res.first * _fact[k % mod], res.second + k/mod};
    }else{
      return {res.first * _fact[k % mod], res.second + k/mod};
    }
  }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    pair<T,ll> numerator = fact(n);
    pair<T,ll> denominator = fact(n);
    if (numerator.second > denominator.second){
      return 0;
    }else{
      return numerator.first/denominator.first;
    }
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    pair<T,ll> numerator = fact(p);
    pair<T,ll> denominator1 = fact(q);
    pair<T,ll> denominator2 = fact(p-q);
    if (numerator.second > denominator1.second + denominator2.second){
      return 0;
    }else{
      return numerator.first / (denominator1.first * denominator2.first);
    }

  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

using modint = ModInt< 3 >;

int main()
{
    Combination<modint> combination;
    for(int i = 0;i < 30;i++){
      for(int j = 0;j <= i;j++){
        cout << combination.C(i,j);
      }
      cout << endl;
    }
    return 0;
}