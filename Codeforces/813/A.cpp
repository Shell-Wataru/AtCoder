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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    a[i]--;
  }
  ll ans = 0;
  for(int i = 0;i < k;i++){
    if (a[i] >= k){
      ans++;
    }
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