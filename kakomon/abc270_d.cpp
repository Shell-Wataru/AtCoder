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
  ll n,k;
  cin >> n >> k;
  vector<ll> A(k);
  vector<ll> DP(n+1);
  for(int i = 0;i < k;i++){
    cin >> A[i];
  }
  for(int i = 1;i <= n;i++){
    ll ans = 0;
    for(int j = 0;j < k;j++){
        if (A[j] <= i){
            ans = max(ans,A[j] + (i-A[j]- DP[i-A[j]]));
        }
    }
    DP[i] = ans;
  }
  cout << DP[n];
  cout << "\n";
  return 0;
}

int main()
{
  // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}