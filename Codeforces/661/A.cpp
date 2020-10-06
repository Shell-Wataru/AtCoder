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
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  bool can_make = true;
  for(int i = 0;i < n-1;i++){
    if (A[i+1] > A[i]+1){
      can_make = false;
    }
  }
  if (can_make){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
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
  return 0;
}