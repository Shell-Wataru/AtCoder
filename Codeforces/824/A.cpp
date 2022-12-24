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
  ll n,k;
  cin >> n >> k;
  vector<vector<ll>> a(k);
  for(int i = 0;i < n;i++){
    ll aa;
    scanf("%lld",&aa);
    a[i%k].push_back(aa);
  }
  ll ans= 0;
  for(int i = 0;i < k;i++){
    sort(a[i].begin(),a[i].end());
    ans += a[i].back();
  }
  cout << ans << "\n";
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