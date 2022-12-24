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
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

struct ArbitraryModInt {

  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y) : x(y >= 0 ? y % mod() : (mod() - (-y) % mod()) % mod()) {}

  static int &mod() {
    static int mod = 0;
    return mod;
  }

  static int set_mod(int md) {
    mod() = md;
    return 0;
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if((x += p.x) >= mod()) x -= mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if((x += mod() - p.x) >= mod()) x -= mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long) x * p.x;
    unsigned xh = (unsigned) (a >> 32), xl = (unsigned) a, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
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

  ArbitraryModInt inverse() const {
    int a = x, b = mod(), u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};

using modint = ArbitraryModInt;
int main()
{
  ll N,M;
  cin >> N >> M;
  modint::set_mod(M);

  vector<vector<modint>> C(N+1,vector<modint>(N+1));
  C[0][0] = 1;
  for(int i = 0;i <= N;i++){
    for(int j = 0;j <= N;j++){
      if (i > 0){
              C[i][j] += C[i-1][j];
      }
      if (j > 0){
              C[i][j] += C[i][j-1];
      }
    }
  }
  vector<vector<modint>> DP(N,vector<modint>(N+1));
  vector<vector<modint>> times(N,vector<modint>(N));
  modint two = 2;
  for(int j = 1;j < N;j++){
    for(int k = 1;k < N;k++){
      times[j][k] = (two.pow(j) -1).pow(k)*two.pow(k*(k-1)/2);
    }
  }
  DP[1][1] = 1;
  for(int i = 1;i < N;i++){
    for(int j = 1;j < N;j++){
      if (DP[i][j] == 0){
        continue;
      }
      for(int k = 1;i+k < N;k++){
        // cout << N-1-i << "," << k  << "="  <<C[N-1-i-k][k]<< endl;
        DP[i+k][k] += DP[i][j]* times[j][k]*C[N-1-i-k][k];
      }
    }
  }
  modint ans = 0;
  for(int i = 1;i< N;i++){
    // cout << i << ":" << DP[N-1][i] << endl;
    ans += DP[N-1][i]*(two.pow(i)-1);
  }
  cout << ans << endl;
  return 0;
}
