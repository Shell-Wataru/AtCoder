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
#include <unordered_map>
using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;
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

ll solve()
{
    ll N,M,S,T;
    cin >> N >> M >> S >> T;
    S--;T--;
    vector<vector<pair<ll,ll>>> G(N);
    vector<vector<ll>> edges(M);
    for(int i = 0;i < M;i++){
        ll u,v,d;
        cin >> u >> v >> d;
        u--;
        v--;
        G[u].push_back({v,d});
        G[v].push_back({u,d});
        edges[i] = {u,v,d};
    }
    vector<modint> DPfromS(N,0);
    vector<modint> DPfromT(N,0);
    DPfromS[S] = 1;
    DPfromT[T] = 1;
    vector<ll> minDfromS(N,numeric_limits<ll>::max()/4);
    vector<ll> minDfromT(N,numeric_limits<ll>::max()/4);
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> qfromS;
    qfromS.push({0,S,-1});
    while(!qfromS.empty()){
        ll d = qfromS.top()[0];
        ll current = qfromS.top()[1];
        ll before = qfromS.top()[2];
        qfromS.pop();
        if (before != -1 && d <= minDfromS[current]){
            DPfromS[current] += DPfromS[before];
        }
        if (d  < minDfromS[current]){
            minDfromS[current] = d;
            for(auto e:G[current]){
                qfromS.push({d+e.second,e.first,current});
            }
        }
    }
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> qfromT;
    qfromT.push({0,T,-1});
    while(!qfromT.empty()){
        ll d = qfromT.top()[0];
        ll current = qfromT.top()[1];
        ll before = qfromT.top()[2];
        qfromT.pop();
        if (before != -1 && d <= minDfromT[current]){
            DPfromT[current] += DPfromT[before];
        }
        if (d  < minDfromT[current]){
            minDfromT[current] = d;
            for(auto e:G[current]){
                qfromT.push({d+e.second,e.first,current});
            }
        }
    }

    modint ans = DPfromS[T] * DPfromT[S];
    // cout << DPfromT[S] << endl;
    // cout << DPfromS[T] << endl;
    ll distance = minDfromS[T];
    // cout << distance << endl;
    for(auto e:edges){
        if (minDfromS[e[1]] - minDfromS[e[0]] == e[2] &&
            2*minDfromS[e[0]] < distance && distance <  2*minDfromS[e[1]] &&
            minDfromS[e[1]] + minDfromT[e[1]] == distance
            ){
            // cout << e[0] +1  << ","<< e[1] + 1 << ","<< e[2] << endl;
            ans -= DPfromS[e[0]]*DPfromT[e[1]]*DPfromS[e[0]]*DPfromT[e[1]];
        }
        if (minDfromS[e[0]] - minDfromS[e[1]] == e[2] &&
             2*minDfromS[e[1]] < distance && distance <  2*minDfromS[e[0]] &&
             minDfromS[e[0]] + minDfromT[e[0]] == distance
             ){
            // cout << e[0] + 1 << ","<< e[1]+1  << ","<< e[2] << endl;
            ans -= DPfromS[e[1]]*DPfromT[e[0]]*DPfromS[e[1]]*DPfromT[e[0]];
        }
    }
    for(int i = 0;i < N;i++){
        if (2*minDfromS[i] == distance){
            // cout << DPfromS[i] << "*" << DPfromT[i] << endl;
            ans -= DPfromS[i]*DPfromT[i]*DPfromS[i]*DPfromT[i];
        }
    }
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
