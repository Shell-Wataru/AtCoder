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

int solve()
{
  ll n;
  string S,T;
  cin >> n;
  cin >> S >> T;
  bool zero_found = false;
  bool one_found = false;
  ll ans = 0;
  for(int i = 0;i < n;i++){
    if (S[i] == '0' && T[i] == '0'){
      if (one_found){
        ans += 2;
        one_found = false;
      }else if (zero_found){
        ans+= 1;
        zero_found = true;
      }else{
        zero_found = true;
      }

    }else if ((S[i] == '0' && T[i] == '1') || (S[i] == '1' && T[i] == '0')){
      ans+= 2;
      if (zero_found){
        ans+= 1;
      }
      zero_found = false;
      one_found = false;
    }else{
      if (zero_found){
        ans += 2;
        zero_found = false;
      }else{
        one_found = true;
      }
    }
  }
  if (zero_found){
    ans++;
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
