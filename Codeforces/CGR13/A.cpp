#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;
int solve()
{
  ll n,q;
  cin >> n >> q;;
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&A[i]);
  }
  ll one_counts = 0;
  for(int i = 0;i < n;i++){
    if (A[i] == 1){
      one_counts++;
    }
  }
  for(int i = 0;i < q;i++){
    ll t,x;
    scanf("%lld",&t);
    scanf("%lld",&x);
    if (t == 1){
      x--;
      if (A[x] == 1){
        one_counts--;
      }else{
        one_counts++;
      }
      A[x] = 1 - A[x];
    }else{
      if (x <= one_counts){
        cout << 1 << "\n";
      }else{
        cout << 0 << "\n";
      }
    }

  }
  cout << flush;
  return 0;
}

int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  return 0;
}