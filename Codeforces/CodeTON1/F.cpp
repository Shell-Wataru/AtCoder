#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

struct ArbitraryModInt
{

  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y) : x(y >= 0 ? y % mod() : (mod() - (-y) % mod()) % mod()) {}

  static int &mod()
  {
    static int mod = 0;
    return mod;
  }

  static int set_mod(int md)
  {
    mod() = md;
    return 0;
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p)
  {
    if ((x += p.x) >= mod())
      x -= mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p)
  {
    if ((x += mod() - p.x) >= mod())
      x -= mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p)
  {
    unsigned long long a = (unsigned long long)x * p.x;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t"
        : "=a"(d), "=d"(m)
        : "d"(xh), "a"(xl), "r"(mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p)
  {
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

  ArbitraryModInt inverse() const
  {
    int a = x, b = mod(), u = 1, v = 0, t;
    while (b > 0)
    {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const
  {
    ArbitraryModInt ret(1), mul(x);
    while (n > 0)
    {
      if (n & 1)
        ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p)
  {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a)
  {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};

int solve()
{

  ll n, q, mod;
  scanf("%lld", &n);
  scanf("%lld", &q);
  scanf("%lld", &mod);
  ArbitraryModInt::set_mod(mod);
  vector<ArbitraryModInt> fib(n + 1);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  // https://theory-and-me.hatenablog.com/entry/2020/08/23/182712
  vector<ArbitraryModInt> a(n + 2, 0);
  vector<ArbitraryModInt> fib_a(n + 2, 0);
  vector<ArbitraryModInt> b(n + 2, 0);
  vector<ArbitraryModInt> fib_b(n + 2, 0);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%lld",&b[i]);
  }
  fib_a[0] = a[0];
  fib_a[1] = a[1] - a[0];
  for (int i = 2; i < n + 2; i++)
  {
    fib_a[i] = a[i] -a[i - 1] - a[i - 2];
  }
  fib_b[0] = b[0];
  fib_b[1] = b[1] - b[0];
  for (int i = 2; i < n + 2; i++)
  {
    fib_b[i] = b[i] - b[i - 1] - b[i - 2];
  }
  // for(int i = 0;i < n+2;i++){
  //   cout << fib_a[i] << ",";
  // }
  // cout << endl;
  // for(int i = 0;i < n+2;i++){
  //   cout << fib_b[i] << ",";
  // }
  // cout << endl;
  ll same_count = 0;
  for (int i = 0; i < n + 2; i++)
  {
    if (fib_a[i] == fib_b[i])
    {
      same_count++;
    }
  }
  // cout << same_count << endl;
  for (int i = 0; i < q; i++)
  {
    char t;
    ll l, r;
    cin >> t;
    scanf("%lld", &l);
    scanf("%lld", &r);
    l--;
    ll before_same = 0;
    ll after_same = 0;
    if (fib_a[l] == fib_b[l])
    {
      before_same++;
    }
    if (fib_a[r] == fib_b[r])
    {
      before_same++;
    }
    if (fib_a[r + 1] == fib_b[r + 1])
    {
      before_same++;
    }
    if (t == 'A')
    {

      fib_a[l] += 1;
      fib_a[r] += - fib[r - l];
      fib_a[r + 1] += - fib[r - l - 1];
    }
    else
    {
      fib_b[l] += 1;
      fib_b[r] += -fib[r - l];
      fib_b[r + 1] += - fib[r - l-1];
    }
    if (fib_a[l] == fib_b[l])
    {
      after_same++;
    }
    if (fib_a[r] == fib_b[r])
    {
      after_same++;
    }
    if (fib_a[r + 1] == fib_b[r + 1])
    {
      after_same++;
    }
    same_count += after_same - before_same;
    // for(int j = 0;j < n+2;j++){
    //   cout << fib_a[j] << ",";
    // }
    // cout << endl;
    // for(int j = 0;j < n+2;j++){
    //   cout << fib_b[j] << ",";
    // }
    // cout << endl;
    if (same_count == n + 2)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}