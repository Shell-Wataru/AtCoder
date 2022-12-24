#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);

  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a.begin(),a.end());
  ll ans = a.back() - a.front();
  for(int i = 2;i < n;i++){
    ans = max(ans,abs(a[0]-a[i]) + abs(a[i]-a[i-1]));
  }
  for(int i = 0;i < n-2;i++){
    ans = max(ans,abs(a[n-1]-a[i]) + abs(a[i]-a[i+1]));
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
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
