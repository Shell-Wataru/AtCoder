#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll ans = numeric_limits<ll>::min();
  for(int i = 1;i < n;i++){
    ans = max(ans,a[i]-a[0]);
  }
  for(int i = 0;i < n-1;i++){
    ans = max(ans,a[n-1]-a[i]);
  }
  for(int i = 0;i < n;i++){
    ans = max(ans,a[i]-a[(i+1)%n]);
  }
  cout << ans;
  cout << "\n";
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