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
  vector<ll>  A(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  ll ans_j = -1;
  for (size_t i = 1; i < n-1; i++)
  {
    if (A[i-1] < A[i] && A[i] > A[i+1]){
      ans_j = i;
    }
  }
  if (ans_j == -1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    cout << ans_j << " " << ans_j + 1 << " " << ans_j + 2 << endl;
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