#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

ll pow(ll x, ll y)
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

int solve()
{
  string n_s;
  cin >> n_s;
  ll n = stoll(n_s);
  ll ans = 0;
  reverse(n_s.begin(),n_s.end());
  for(int i = 0;i < max(1ll<<(n_s.size()-2),1ll);i++){
    // cout << i << endl;
    ll real_n = n;
    ll current_ans = 1;
    for(int k = 0;k < n_s.size();k++){
      ll d;
      if (k-2 >= 0 && (i & (1ll<<(k-2))) ){
        real_n -= pow(10,k);
        real_n += pow(10,k-1);
        d = (n_s[k] - '0' + 9) % 10;
      }else{
        d = n_s[k] - '0';
      }
      // cout << "k" << k << endl;
      // cout << "d" << d << endl;
      if(i & (1ll<<k)){
        if (d == 9){
          if (k-2 >= 0 && (i & (1ll<<(k-2)))){
            current_ans *= d + 1;
          }else{
            current_ans *= 0;
          }
        }else{
          current_ans *= 9 - d;
        }
      }else{
        if (d == 9){
          if (k-2 >= 0 && (i & (1ll<<(k-2)))){
            current_ans *= 0;
          }else{
            current_ans *= d + 1;
          }
        }else{
          current_ans *= d + 1;
        }
      }
    }
    // cout << current_ans << endl;
    // cout << "real_n:" <<  real_n << endl;
    if (real_n > 0){
      ans += current_ans;
    }
  }
  ans -= 2;
  cout << ans << "\n";
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
