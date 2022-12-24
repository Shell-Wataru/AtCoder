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
  vector< T > _fact;
  vector<ll> _ord;
  ll mod;

  Combination(int sz) : _fact(sz + 1), _ord(sz + 1), mod(T::get_mod()) {
    _fact[0] = 1;
    _fact[1] = 1;
    _ord[0]= 0;
    _ord[1]= 0;
    for (int i = 2; i <= sz; i++) {
        long long add = 0;
        long long ni = i;
        while (ni % mod == 0) ++add, ni /= mod;
        _ord[i] = _ord[i-1] + add;
        _fact[i] = _fact[ni-1] * ni;
    }
  }

  inline T fact(int k) const { return _fact[k]; }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    ll e = _ord[p] - _ord[q] - _ord[p-q];
    if (e == 0){
      return  _fact[p] / (_fact[q] * _fact[p-q]);
    }else{
      return 0;
    }
  }
};

using modint = ModInt< 3 >;

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;
  Combination<modint> C(400000);
  modint two(2);
  modint base = two.pow(N-1);
  modint ans = 0;

  for(int i = 0;i < N;i++){
      if (S[i] == 'B'){
        ans += C.C(N-1,i) * base * 0;
      }else if (S[i] == 'W'){
          ans += C.C(N-1,i) * base * 1;
      }else{
          ans += C.C(N-1,i) * base * 2;
      }
  }
  if (ans.x == 0){
      cout << "B" << endl;
  }else if(ans.x == 1){
      cout << "W" << endl;
  }else{
      cout << "R" << endl;
  }
  return 0;
}
