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
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  ll odds = 0;
  ll evens = 0;
  for(int i = 0;i < n;i++){
    if (a[i] % 2 == 0){
      evens++;
    }else{
      odds++;
    }
  }
  if (abs(evens - odds) > 1){
    cout << -1 << "\n";
  }else{
    if (evens > odds){
      ll even_count = 0;
      ll ans = 0;
      for(int i = 0;i < n;i++){
        if (a[i] % 2 == 0){
          ans += abs(2*even_count - i);
          even_count++;
        }
      }
      cout << ans << "\n";
    }else if (odds > evens){
      ll odds_count = 0;
      ll ans = 0;
      for(int i = 0;i < n;i++){
        if (a[i] % 2 == 1){
          ans += abs(2*odds_count - i);
          odds_count++;
        }
      }
      cout << ans << "\n";
    }else{
      ll even_count = 0;
      ll even_ans = 0;
      for(int i = 0;i < n;i++){
        if (a[i] % 2 == 0){
          even_ans += abs(2*even_count - i);
          even_count++;
        }
      }
      ll odds_count = 0;
      ll odds_ans = 0;
      for(int i = 0;i < n;i++){
        if (a[i] % 2 == 1){
          odds_ans += abs(2*odds_count - i);
          odds_count++;
        }
      }
      cout << min(even_ans,odds_ans) << "\n";
    }
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
  cout << flush;
  return 0;
}