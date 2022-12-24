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

int solve()
{
  ll N, M, K, S, T, X;
  cin >> N >> M >> K >> S >> T >> X;
  S--;
  T--;
  X--;
  vector<vector<ll>> G(N);
  vector<vector<modint>> DP_fromS(N, vector<modint>(K + 1));
  vector<vector<modint>> DP_fromT(N, vector<modint>(K + 1));
  vector<vector<modint>> DP_fromX(2 * N, vector<modint>(K + 1));
  for (int i = 0; i < M; i++)
  {
    ll a, b, c;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  DP_fromS[S][0] = 1;
  DP_fromT[T][0] = 1;
  DP_fromX[X][0] = 1;
  for (int k = 0; k < K; k++)
  {
    for (int i = 0; i < N; i++)
    {
      if (i == X)
      {
        continue;
      }
      for (auto to : G[i])
      {
        DP_fromS[to][k + 1] += DP_fromS[i][k];
      }
    }
  }
  for (int k = 0; k < K; k++)
  {
    for (int i = 0; i < 2*N; i++)
    {
      for (auto to : G[i%N])
      {
        if (i >= N){
          if (to == X){
            DP_fromX[to][k + 1] += DP_fromX[i][k];
          }else{
            DP_fromX[to+N][k + 1] += DP_fromX[i][k];
          }
        }else{
          if (to == X){
            DP_fromX[to+N][k + 1] += DP_fromX[i][k];
          }else{
            DP_fromX[to][k + 1] += DP_fromX[i][k];
          }
        }

      }
    }
  }

  for (int k = 0; k < K; k++)
  {
    for (int i = 0; i < N; i++)
    {
      if (i == X)
      {
        continue;
      }
      for (auto to : G[i])
      {
        DP_fromT[to][k + 1] += DP_fromT[i][k];
      }
    }
  }

  modint ans = 0;
  // cout << "fromS" << endl;
  // for (int i = 1; i <= K; i++)
  // {

  //   cout << DP_fromS[X][i] << endl;
  // }
  // cout << "fromX" << endl;

  // for (int i = 1; i <= K; i++)
  // {
  //   cout << DP_fromX[X][i] << endl;
  // }
  // cout << "fromT" << endl;
  // for (int i = 1; i <= K; i++)
  // {
  //   cout << DP_fromT[X][i] << endl;
  // }
  ans += DP_fromS[T][K];
  for (int i = 1; i <= K; i++)
  {
    for (int j = 1; i + j <= K; j++)
    {
      ans += DP_fromS[X][i] * DP_fromX[X+N][j] * DP_fromT[X][K - i - j];
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
