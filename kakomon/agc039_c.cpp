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

const long long BASE_NUM = 998244353;
// https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
//  https://ei1333.github.io/luzhiled/snippets/math/combination.html
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

template <typename T>
struct Combination
{
  vector<T> _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1)
  {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for (int i = 1; i <= sz; i++)
      _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for (int i = sz - 1; i >= 0; i--)
      _rfact[i] = _rfact[i + 1] * (i + 1);
    for (int i = 1; i <= sz; i++)
      _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const
  {
    if (r < 0 || n < r)
      return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const
  {
    if (q < 0 || p < q)
      return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const
  {
    if (n < 0 || r < 0)
      return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

using modint = ModInt<BASE_NUM>;
modint two = 2;

modint patterns(string prefix,ll n){
    modint ret = 0;
    vector<modint> dp(n+2,0);
    for(int i = 0;(1ll<<i) <= n;i++){
        if (n % (1ll<<i) == 0){
            ll m = n/(1ll<<i);
            if (prefix.size() <= m){
                if (i % 2  == 0){
                    ret += two.pow(m - prefix.size());
                }else{
                    ret -= two.pow(m - prefix.size());
                }
            }else{
                bool is_ok = true;
                for(int j = 0;j < m;j++){
                    ll x0 = prefix[j] - '0';
                    for(int k = 1;m*k < prefix.size();k++){
                        ll x1 = prefix[m*k] -'0';
                        if (x0 != (x1 +k) % 2 ){
                            is_ok = false;
                            break;
                        }
                    }
                }
            }
        }
    }
}

ll solve(){
  ll N;
  cin >> N;
  string X;
  cin >> X;

  modint ans = 0;
  modint other = 0;
  for(int i = 1;i < N;i++){
      if (N % i == 0 && (N/i) % 2 == 1){
          cout << i << endl;
          for(int j = 0;j < i;j++){
              if (X[j] == '1'){
                  other += two.pow(i-1-j);
                  ans += two.pow(i-1-j) * 2*i;
              }
          }
          bool lower = true;
          for(int j = 0;j < N;j++){
              char x;
              if (j % (2*i) < i){
                  x = X[j%i];
              }else{
                  if (X[j%i] == '1'){
                      x = '0';
                  }else{
                      x = '1';
                  }
              }
              if (x > X[j]){
                  lower = false;
                  break;
              }else if (x < X[j]){
                  lower = true;
                  break;
              }else{

              }
          }
          if (lower){
              cout << "lower!!" << endl;
              other += 1;
              ans += 2*i;
          }
      }
  }
  modint total = 1;
  for(int i = N-1;i>=0;i--){
      if (X[i] == '1'){
          total += two.pow(N-1-i);
      }
  }
  total -= other;
//   cout << other << endl;
//   cout << total << endl;
  ans += total * 2*N;
  cout << ans << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
    solve();
  // }
  cout << flush;
  return 0;
}
