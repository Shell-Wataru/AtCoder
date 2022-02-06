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

ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2);
        ll yy = (y_2 * y_2);
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x);
        }
    }
}

ll ones(ll x)
{
    ll ans = 0;
    for(int i = 0;i < x;i++){
      ans *= 10;
      ans++;
    }
    return ans;
}

int solve(){
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll i = 1;i<=15;i++){
    ll base = ones(i);
    for(ll j = 0;j <= 15;j++){
      ll current = base * my_pow(10,j);
      ll remain = min(N - current,my_pow(10,j)-1);
      if (remain >= 0){
        // cout << current << ":";
        if (j == 0){
          // cout << 1 << endl;
          ans+= i;
        }else if (remain >= 2*my_pow(10,j-1)){
          // cout << (remain - my_pow(10,j-1) +1) << endl;
          ans += i*(remain - my_pow(10,j-1) + 1);
        }else if (remain >= my_pow(10,j-1)){
          // cout << (my_pow(10,j-1)) << endl;
          ans += i*my_pow(10,j-1);
        }else{
          // cout << (remain+1) << endl;
          ans += i*(remain + 1);
        }
      }else{
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
int main()
{
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
    solve();
  // }
  // cout << flush;
  return 0;
}