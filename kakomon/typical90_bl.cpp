#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,q;
  scanf("%lld", &n);
  scanf("%lld", &q);
  vector<ll> A(n);
  vector<ll> d(n-1);
  for(int i = 0;i < n;i++){
      cin >> A[i];
  }
  ll ans = 0;
  for(int i = 0;i < n-1;i++){
      d[i] = A[i+1]-A[i];
      ans += abs(d[i]);
  }
  for(int i = 0;i < q;i++){
      ll l,r,v;
      cin >> l >> r >> v;
      l--;r--;
      if (l > 0){
          ll last_d = abs(d[l-1]);
          d[l-1] += v;
          ans += abs(d[l-1]) - last_d;
      }
      if (r < n-1){
          ll last_d = abs(d[r]);
          d[r] -= v;
          ans += abs(d[r]) - last_d;
      }
      cout << ans << "\n";
  }
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