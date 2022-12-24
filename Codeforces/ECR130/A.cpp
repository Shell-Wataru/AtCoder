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
  ll n,m;
  cin >> n >> m;
  vector<ll> A(n);
  ll total = 0;
  for(int i = 0;i < n;i++){
    scanf("%lld",&A[i]);
    total += A[i];
  }
  cout << max(0ll,total - m) << endl;
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