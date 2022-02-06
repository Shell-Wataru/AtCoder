#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
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
using modint = ModInt< BASE_NUM >;

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<ll> f(n);
  modint ans = 0;
  for(int i = 0;i< n;i++){
      cin >> f[i];
      f[i]--;
  }
  vector<ll> to(n);
  vector<bool> contains(m,false);
  ll last = n;
  for(int i = n-1;i>=0;i--){
      if (contains[f[i]]){
          while(f[last-1] != f[i]){
              last--;
              contains[f[last]] = false;
          }
          last--;
          contains[f[i]] = true;
          to[i] = last;
      }else{
          contains[f[i]] = true;
          to[i] = last;
      }
  }
//   cout << "!" << endl;
  vector<modint> pattern_sums(n+2,0);
  pattern_sums[n+1] = 0;
  pattern_sums[n] = 1;
  pattern_sums[n-1] = 2;
//   cout << 4 << ":to" << to[4] << ":p" << 1 << endl;
  for(int i = n-2;i>=0;i--){
      modint pattern = pattern_sums[i+1] - pattern_sums[to[i]+1];
    //   cout << i << ":to" << to[i] << ":p" << pattern << endl;
      pattern_sums[i] = pattern_sums[i+1] + pattern;
  }
  cout << pattern_sums[0] - pattern_sums[1] << endl;
  return 0;
}
int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}