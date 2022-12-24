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
  ll n,q;
  cin >> n >> q;
  vector<ll> A(n);
  for(int i = 0;i < n;i++){
    cin >> A[i];
  }
  reverse(A.begin(),A.end());
  ll current_q = 0;
  string ans;
  for(int i = 0;i < n;i++){
    if (current_q < A[i]){
      if (current_q < q){
        current_q++;
        ans += '1';
      }else{
        ans += '0';
      }
    }else{
      ans += '1';
    }
  }
  reverse(ans.begin(),ans.end());
  cout << ans;
  cout << "\n";
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