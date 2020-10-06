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

int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> B(n);
  vector<ll> C(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  for (size_t i = 0; i < n; i++)
  {
    cin >> B[i];
  }

  for (size_t i = 0; i < n; i++)
  {
    cin >> C[i];
  }
  vector<ll> ans(n,-1);
  for(int i = 0;i < n;i++){
    ll prev = (n + i - 1) % n ;
    ll next = (i+1) %n;
    if (ans[prev] == -1 ){
      ans[i] = A[i];
    }else if (ans[next ] == -1 ){
      if (A[i] != ans[prev]){
        ans[i] = A[i];
      }else{
        ans[i] = B[i];
      }
    }else{
      if (A[i] != ans[prev] && A[i] != ans[next]){
        ans[i] = A[i];
      }else if (B[i] != ans[prev] && B[i] != ans[next]){
        ans[i] = B[i];
      }else{
        ans[i] = C[i];
      }
    }
  }
  for (size_t i = 0; i < n; i++)
  {
    if (i != 0){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
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
  return 0;
}