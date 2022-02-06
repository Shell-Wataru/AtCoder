#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve(){
  ll N1,N2,N3;
  cin >> N1 >> N2 >> N3;
  N2 /= 2;
  ll ans = 0;
  ll a = min(N2,N3);
  ans += a;
  N2 -= a;
  N3 -= a;
  // cout << a << endl;
  if (N2 > 0){
    ll b = min(N1/2,N2);
    ans += b;
    N1 -= 2*b;
  }else if(N3 > 0){
    ll b = min(N1,N3/2);
    // cout << b << endl;
    ans += b;
    N1 -= b;
    N3 -= 2*b;
    ll c = min(N1/3,N3);
    // cout << c << endl;
    ans += c;
    N1 -= 3*c;
    N3 -= c;
  }
  ans += N1/5;

  cout << ans << "\n";
  return 0;
}
int main()
{
  ll T;
  cin >> T;
  for(int i = 0;i < T;i++){
    solve();
  }
  cout << flush;
  return 0;
}