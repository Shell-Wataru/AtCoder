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
  ll n,d;
  cin >> n >> d;
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    /* code */
    scanf("%lld",&A[i]);
  }
  sort(A.begin(),A.end());

  if(A.back() <= d || A[0] + A[1] <= d){
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