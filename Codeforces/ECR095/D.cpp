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
ll BASE_NUM = 998244353;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> A(n);
  vector<vector<ll>> paircounts(n+1,vector<ll>(n+1,0));
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&A[i]);
  }


  ll ans = 0;
  for(int i = 0;i < n;i++){
    map<ll,ll> front_counts;
    map<ll,ll> back_counts;
    ll total_pair = 0;
    for(int j = i+2;j < n;j++){
      back_counts[A[j]]++;
    }
    for(int j = i+2;j < n;j++){
      front_counts[A[j-1]]++;
      back_counts[A[j]]--;
      if (A[j-1] == A[j]){
        // cout << "same" << endl;
        // cout << front_counts[A[j-1]] * back_counts[A[j]] << endl;
        total_pair += front_counts[A[j-1]] * back_counts[A[j]]  - (front_counts[A[j-1]] - 1) * (back_counts[A[j]] + 1);
      }else{
        total_pair += back_counts[A[j-1]];
        total_pair -= front_counts[A[j]];
      }
      if (A[i] == A[j]){
        ans += total_pair;
      }
      // cout  << "i" << i<< "j"<< j <<":" << total_pair << endl;
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}