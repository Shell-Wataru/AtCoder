#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  string S;
  cin >> S;
  if(n % 2 == 0){
    ll ans = 2;
    for(int i = 1;n/2+i < n;i++){
      if (S[n/2] == S[n/2+i]){
        ans += 2;
      }else{
        break;
      }
    }
    cout << ans << "\n";
  }else{
    ll ans = 1;
    for(int i = 1;n/2+i < n;i++){
      if (S[n/2+i] == S[n/2]){
        ans += 2;
      }else{
        break;
      }
    }
    cout << ans << "\n";
  }
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