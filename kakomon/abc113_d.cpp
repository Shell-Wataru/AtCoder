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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}
struct fast_ios
{
    fast_ios()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

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

using modint = ModInt< 1000000007 >;

int main()
{
    // 整数の入力
    ll H,W,K;
    cin >> H >> W >> K;
    if (W == 1){
        cout << 1 << endl;
        return 0;
    }
    auto dp = make_vec(H+1,W,modint(0));
    dp[0][0] = 1;
    for(int i = 1;i <= H;i++){
        for(int j = 0;j < (1<<(W-1));j++){
            bool is_valid = true;
            for(int k = 0;k < W-2;k++){
                if ((j & 1<<k) && (j & 1<<(k+1))){
                    is_valid = false;
                }
            }
            if (!is_valid){
                continue;
            }

            ll zero_move_to;
            if (j & 1<<0){
                zero_move_to = 1;
            }else{
                zero_move_to = 0;
            }
            dp[i][zero_move_to] += dp[i-1][0];

            ll end_move_to;
            if (j & 1<<(W-2)){
                end_move_to = W-2;
            }else{
                end_move_to = W-1;
            }
            dp[i][end_move_to] += dp[i-1][W-1];

            for(int k = 0;k < W-2;k++){
                ll move_to;
                if (j & 1<<k){
                    move_to = k;
                }else if(j & 1<<(k+1)){
                    move_to = k + 2;
                }else{
                    move_to = k + 1;
                }
                dp[i][move_to] += dp[i-1][k+1];
            }
        }
    }
    // for(int i = 0;i < W;i++){
    //     cout << dp[H][i] << ",";
    // }
    // cout << endl;
    cout << dp[H][K-1] << endl;
   return 0;
}