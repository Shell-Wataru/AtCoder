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

ll pow(ll x, ll y, ll modulo)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2, modulo) % modulo;
        ll yy = (y_2 * y_2) % modulo;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % modulo;
        }
    }
}

int64_t mod_log(int64_t a, int64_t b, int64_t p) {
  int64_t g = 1;

  for(int64_t i = p; i; i /= 2) (g *= a) %= p;
  g = gcd(g, p);

  int64_t t = 1, c = 0;
  for(; t % g; c++) {
    if(t == b) return c;
    (t *= a) %= p;
  }
  if(b % g) return -1;

  t /= g;
  b /= g;

  int64_t n = p / g, h = 0, gs = 1;

  for(; h * h < n; h++) (gs *= a) %= n;

  unordered_map< int64_t, int64_t > bs;
  for(int64_t s = 0, e = b; s < h; bs[e] = ++s) {
    (e *= a) %= n;
  }

  for(int64_t s = 0, e = t; s < n;) {
    (e *= gs) %= n;
    s += h;
    if(bs.count(e)) return c + s - bs[e];
  }
  return -1;
}

ll solve(){
  ll X,P,A,B;
  cin >> X >> P >> A >> B;
  if (B-A <= 1000000){
      ll current = pow(X,A,P);
      ll ans = current;
      for(int i = 0;i <= B-A;i++){
          ans =min(ans,current);
          current *= X;
          current %= P;
      }
      cout << endl;
  }else{
    ll invX = pow(X,P-2,P);
    ll invX_A = pow(invX,A,P);
    for(int i = 0;i < 100000;i++){
        ll x = mod_log(X,(i*invX_A) % P,P);
        if (0 <= x && x <= B-A){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
  }
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
