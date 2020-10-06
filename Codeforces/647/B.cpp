#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

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

using modint = ModInt<BASE_NUM>;
void add_second(map<ll,ll> &first,map<ll,ll> &second,ll p,ll k){
    if(first.find(k) != first.end()){
        first.erase(k);
    }else{
        second[k]++;
        if (second[k] == p){
            second.erase(k);
            add_second(first,second,p,k+1);
        }
    }
}
int solve()
{
    ll n,p;
    cin >> n >> p;
    vector<ll> ks(n);
    for(int i = 0;i < n;i++){
        scanf("%lld" ,&ks[i]);
    }
    sort(ks.begin(),ks.end(),greater<ll>());
    if (p == 1){
        cout << n % 2 << endl;
    }else{
        map<ll,ll> first,second;
        for(int i = 0;i < n;i++){
            if (first.empty()){
                first[ks[i]]++;
            }else{
                add_second(first,second,p,ks[i]);
            }
        }
        modint first_sum = 0;
        modint second_sum = 0;
        modint pp = p;
        // cout << "f" << endl;
        for(auto pa:first){
            // cout << pa.first << " " << pa.second << endl;
            first_sum += pp.pow(pa.first) * pa.second;
        }
        // cout << "Se" << endl;
        for(auto pa:second){
            // cout << pa.first << " " << pa.second << endl;
            second_sum += pp.pow(pa.first) * pa.second;
        }
        cout << first_sum - second_sum << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
