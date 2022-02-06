#include <iostream>
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

int solve()
{
  ll n,k;
  scanf("%lld", &n);
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&b[i]);
  }
  ll base = 0;
  for (size_t i = 0; i < n; i++)
  {
    base += a[i]*b[i];
  }
  ll ans = base;
  for(int i = 0;i < n;i++){
    ll current = base;
    for(int j = 1;j<n;j++){
      if (i - j < 0 || i+j >= n){
        break;
      }
      ll x = i - j;
      ll y = i + j;
      current += a[x]*b[y] + a[y]*b[x] - a[x]*b[x] - a[y]*b[y];
      ans = max(ans,current);
    }
  }
  for(int i = 0;i < n;i++){
    ll current = base;
    for(int j = 0;j<n;j++){
      ll x = i - j;
      ll y = i + 1 + j;
      if (x < 0 || y >= n){
        break;
      }
      current += a[x]*b[y] + a[y]*b[x] - a[x]*b[x] - a[y]*b[y];
      ans = max(ans,current);
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}