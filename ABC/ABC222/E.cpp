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
//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
// https://ei1333.github.io/luzhiled/snippets/math/combination.html
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

bool dfs(vector<vector<pair<ll, ll>>> &G,vector<ll> &counts, ll current,ll parent,ll target){
  if (current == target){
    return true;
  }
  for(auto e:G[current]){
    ll to = e.second;
    if(to != parent){
      bool found = dfs(G,counts,to,current,target);
      if (found){
        counts[e.first]++;
        return true;
      }
    }
  }
  return false;
}
int main()
{
  ll N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(M);
  vector<vector<pair<ll, ll>>> G(N);
  vector<ll> counts(N-1,0);
  for (int i = 0; i < M; i++)
  {
    cin >> A[i];
    A[i]--;
  }
  for (int i = 0; i < N-1; i++)
  {
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back({i,v});
    G[v].push_back({i,u});
  }
  for(int i = 0;i < M-1;i++){
    dfs(G,counts,A[i],-1,A[i+1]);
  }
  // for(auto c:counts){
  //   cout << c << ",";
  // }
  // cout << endl;
  ll total_edges = 0;
  for(auto c:counts){
    total_edges += c;
  }
  if (K > total_edges || K < - total_edges){
    cout << 0 << endl;
    return 0;
  }
  vector<modint> DP(total_edges+1,0);
  DP[0] = 1;
  for(int i = 0;i < N-1;i++){
    vector<modint> newDP = DP;
    for(int j = 0;j + counts[i] <= total_edges;j++ ){
      newDP[j+counts[i]] += DP[j];
    }
    swap(DP,newDP);
  }
  if ( (total_edges + K) % 2 != 0){
    cout << 0 << endl;
  }else{
    cout << DP[(total_edges+K)/2] << endl;
  }
  return 0;
}
