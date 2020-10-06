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

  bool is_clear = false;
  for (size_t i = 0; i < n-1; i++)
  {
    if (A[i] <= A[i+1]){
      is_clear = true;
    }
  }
  if (is_clear){
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