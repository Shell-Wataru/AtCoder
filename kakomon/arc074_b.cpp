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
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> A(3*n);
  priority_queue<ll,vector<ll>,greater<ll>> small_q;
  priority_queue<ll> big_q;
  vector<ll> first_half(3*n+1,0);
  vector<ll> second_half(3*n+1,0);
  for(int i = 0;i < 3*n;i++){
      cin >> A[i];
  }
  ll first_total = 0;
  for(int i = 0;i < 3*n;i++){
    first_total += A[i];
    small_q.push(A[i]);
    if (small_q.size() > n){
        first_total -= small_q.top();
        small_q.pop();
    }
    first_half[i+1] = first_total;
  }
  ll second_total = 0;
  for(int i = 3*n -1;i >= 0;i--){
    second_total += A[i];
    big_q.push(A[i]);
    if (big_q.size() > n){
        second_total -= big_q.top();
        big_q.pop();
    }
    second_half[i] = second_total;
  }
  ll ans = numeric_limits<ll>::min();
  for(int i = n;i <= 2*n;i++){
      ans = max(ans,first_half[i] - second_half[i]);
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
  solve();
//   }
//   cout << flush;
  return 0;
}
