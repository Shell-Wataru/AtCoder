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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

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


int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> G(H,vector<ll>(W));
    vector<vector<modint>> DP(H,vector<modint>(W,1));
    priority_queue<vector<ll>> q;
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            cin >> G[i][j];
            q.push({G[i][j],i,j});
        }
    }
    vector<pair<ll,ll>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    while(!q.empty()){
        auto current = q.top();
        q.pop();
        for(auto d:directions){
            ll next_x = current[1] + d.first;
            ll next_y = current[2] + d.second;
            if (0 <= next_x && next_x < H && 0 <= next_y && next_y < W && G[next_x][next_y] > current[0]){
                DP[current[1]][current[2]] +=  DP[next_x][next_y];
            }
        }
    }
    modint ans = 0;
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            ans += DP[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}