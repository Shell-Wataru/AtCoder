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
const long long BASE_NUM = 1000000007;


int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  if (n == 1){
    cout << 0 << "\n";
    return 0;
  }
  sort(a.begin(),a.end());
  ll ans = a.back();
  for(int i = 0;i < n-1;i++){
    ll d = a[i+1]-a[i];
    ans -= d*(i+1)*(n-i-1);
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
