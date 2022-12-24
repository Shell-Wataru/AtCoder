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

using namespace std;
using ll = long long;

ll min_b(ll N,ll a,ll l,ll r){
  if (l+ 1 == r){
    return r;
  }
  ll b = (l+r)/2;
  ll x = a*a*a + a*a *b + a*b*b + b*b*b;
  if (x >= N){
    return min_b(N,a,l,b);
  }else{
    return min_b(N,a,b,r);
  }
}

int solve()
{
  ll N;
  cin >> N;
  ll x = numeric_limits<ll>::max();
  // cout << 1000000ll*1000000ll*1000000ll*4 << endl;
  for(ll a = 0;a <= 1000000;a++){
    ll b= min_b(N,a,-1,1000000);
    x = min(x, a*a*a + a*a *b + a*b*b + b*b*b);
  }
  cout << x << endl;
  return 0;
}

int main()
{
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  // cout << flush;
  return 0;
}
