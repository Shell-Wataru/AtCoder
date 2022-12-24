#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
  string s;
  cin >> s;
  ll n = s.size();
  vector<ll> ruiseikiWa(n+1);
  for(int i = 0;i < n;i++){
    if (s[i] == '0'){
      ruiseikiWa[i+1] += ruiseikiWa[i] + 1;
    }else{
      ruiseikiWa[i+1] += ruiseikiWa[i];
    }
    // cout << ruiseikiWa[i+1] << endl;
  }

  ll ans =numeric_limits<ll>::max();
  for(int i = 0;i < n;i++){

    ll l = i;
    ll r = n+1;
    while(l + 1 < r){
      ll center = (l+r)/2;
      ll removed_ones = i - ruiseikiWa[i] + (n - center)  - (ruiseikiWa[n] - ruiseikiWa[center]);
      ll remain_zeros = ruiseikiWa[center] - ruiseikiWa[i];
      if (removed_ones < remain_zeros){
        r = center;
      }else{
        l = center;
      }
    }
    // cout << i << ":" << r << endl;
    ll ones = i - ruiseikiWa[i] + (n - l)  - (ruiseikiWa[n] - ruiseikiWa[l]);
    ll zeros = ruiseikiWa[l] - ruiseikiWa[i];
    ans = min(ans,max(zeros,ones));
  }
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
