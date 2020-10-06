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
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> P;
  vector<ll> N;
  ll zero_count = 0;
  for(int i = 0;i < n;i++){
    ll a;
    cin >> a;
    if (a > 0){
      P.push_back(a);
    }else if(a < 0){
      N.push_back(- a);
    }else if (a == 0){
      zero_count++;
    }
  }
  sort(P.begin(),P.end());
  sort(N.begin(),N.end());
  ll ans = numeric_limits<ll>::min();
  for(int p_length = 0;p_length <= 5;p_length++){
    for(int n_length = 0;n_length <= 5 - p_length; n_length++){
      ll zero_length = 5 - p_length - n_length;
      if (P.size() < p_length || N.size() < n_length || zero_count < zero_length){
        continue;
      }
      // cout << "!!!" << endl;
      if (zero_length > 0){
        ans = max(ans,0ll);
      }else if(n_length % 2 == 0){
        ll current = 1;
        for(int i = 0;i < p_length;i++){
          current *= P[P.size()-1-i];
        }
        for(int i = 0;i < n_length;i++){
          current *= N[N.size()-1-i];
        }
        ans = max(ans,current);
      }else{
        ll current = 1;
        for(int i = 0;i < p_length;i++){
          current *= P[i];
        }
        for(int i = 0;i < n_length;i++){
          current *= N[i];
        }
        ans = max(ans,- current);
      }
    }
  }
  cout << ans << endl;
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
