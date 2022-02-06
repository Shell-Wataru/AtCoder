\

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
  ll n;
  cin >> n;
  vector<ll> A(n);
  ll total = 0;
  for(int i = 0;i < n;i++){
    scanf("%lld",&A[i]);
    total += A[i];
  }
  sort(A.begin(),A.end());
  ll max_v = A.back();
  cout << fixed << setprecision(12) << max_v + 1.0* (total-max_v)/(n-1) << "\n";
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