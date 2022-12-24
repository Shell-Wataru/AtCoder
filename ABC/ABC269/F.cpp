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
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

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


int main()
{
  ll N,M;
  ll Q;
  cin >> N >> M >> Q;
  modint one = 1;
  for(int i = 0;i < Q;i++){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll rows =  b-a+1;
    ll columns = d-c+1;
    modint ans = one * (rows/2) * (columns/2) * ( one*2*c+1 + one*2*c+1+4*(columns/2-1))/2
          +  one * (rows/2) * (columns/2) * ( one *M*(2*a-1) + one *M*(2*a-1)+4*M*(rows/2-1))/2;
    // cout << ans << endl;
    if (rows % 2 == 1){
      ll from = c;
      ll to = d;
      if ((b+from) % 2 ==1){
        from++;
      }
      if ((b+to) % 2 ==1){
        to--;
      }
      // cout << from << "~" << to << endl;
      // cout << ((M*(b-1)+from)+(M*(b-1)+to))* ( (to-from)/2 + 1)/2 << endl;
      ans += one * ((M*(b-1)+from)+(M*(b-1)+to))* ( (to-from)/2 + 1)/2;
    }
    if (columns % 2 == 1){
      ll from = a;
      ll to = b;
      if ((from+d) % 2 ==1){
        from++;
      }
      if ((to+d) % 2 ==1){
        to--;
      }
      // cout << from << "~" << to << endl;
      // cout << ((M*(from-1)+d)+(M*(to-1)+d))* ( (to-from)/2 + 1)/2 << endl;
      ans += one * ((M*(from-1)+d)+(M*(to-1)+d))* ( (to-from)/2 + 1)/2;
    }
    if (rows % 2 == 1 && columns % 2 == 1){
      if ((b+d)% 2 != 1){
        // cout << "!" << endl;
        ans -= one * (M*(b-1)+d);
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
