#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,u,v;
  cin >> n >> u >> v;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll ans =numeric_limits<ll>::max();
  for(int i = 1;i < n;i++){
    if (abs(a[i] - a[i-1]) == 0){
      ans = min(min(u + v,2*v),ans);
    }else if(abs(a[i] - a[i-1]) == 1){
      ans = min(min(u,v),ans);
    }else{
      ans = 0;
    }
  }
  cout << ans << "\n";

  return 0;
}
int main()
{
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
