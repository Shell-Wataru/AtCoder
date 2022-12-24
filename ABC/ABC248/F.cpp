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

int solve()
{
    ll N,P;
    cin >> N >> P;
    ArbitraryModInt::set_mod(P);
    vector<vector<ArbitraryModInt>> DP_A(N+1,vector<ArbitraryModInt>(2*N,0));
    vector<vector<ArbitraryModInt>> DP_B(N+1,vector<ArbitraryModInt>(2*N,0));
    DP_A[1][0] = 1;
    DP_B[1][1] = 1;
    for(int i = 1;i < N;i++){
        for(int j = 0;j <= N;j++){
            // =
            DP_A[i+1][j+1] += DP_A[i][j];
            DP_B[i+1][j+1] += DP_B[i][j];
            // コ
            DP_A[i+1][j] += DP_A[i][j];
            DP_A[i+1][j] += DP_B[i][j];
            // _
            DP_B[i+1][j+2] += DP_A[i][j];
            // -
            DP_B[i+1][j+2] += DP_A[i][j];
            //  |
            // □
            //
            DP_A[i+1][j+1] += DP_A[i][j];
            DP_A[i+1][j+1] += DP_A[i][j];
        }
    }
    for(int i = 1; i < N;i++){
        if (i != 1){
            cout << " ";
        }
        cout << DP_A[N][i];
    }
    cout << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
