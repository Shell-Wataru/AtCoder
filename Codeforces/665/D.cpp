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

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

using modint = ModInt< BASE_NUM >;

int dfs1(int from, int parent, vector<vector<ll>> &G, map<pair<ll,ll>,ll> &paths)
{
    ll size = 1;
    for (auto &to : G[from])
    {
        if (to != parent)
        {
            ll to_children = dfs1(to, from, G, paths);
            size += to_children;
            paths[{from,to}] = to_children * (G.size() - to_children);
        }
    }
    return size;
}

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  vector<vector<ll>> G(n);
  map<pair<ll,ll>,ll> paths;
  for (int i = 0; i <n-1; i++)
    {
        ll a,b;
        scanf("%lld",&a);
        scanf("%lld",&b);
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
  dfs1(0,-1,G,paths);
  scanf("%lld",&m);
  vector<ll> primes(m);
  for (size_t i = 0; i < m; i++)
  {
    scanf("%lld",&primes[i]);
  }
  if (m < n- 1){
    for(int i = 0;i < (n-1) - m;i++){
      primes.push_back(1);
    }
  }
  sort(primes.begin(),primes.end());
  vector<modint> modint_primes(primes.begin(),primes.end());
  if (m > n - 1){
    for(int i = 0;i < m - (n-1);i++){
      modint a = modint_primes.back();
      modint_primes.pop_back();
      modint_primes.back() *= a;
    }
  }
  vector<ll> path_weights;
  for(auto &p: paths){
    path_weights.push_back(p.second);
  }
  sort(path_weights.begin(),path_weights.end());
  modint ans = 0;

  for(int i = 0;i < n-1;i++){
    ans += modint_primes[i] * path_weights[i];
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}