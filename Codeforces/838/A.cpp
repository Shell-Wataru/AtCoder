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
  ll total = 0;
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i < n;i++){
    cin >> a[i];
    total += a[i];
    bool first_bit = a[i] & 1ll<<0;
    for(ll j = 1;j < 30;j++){
      bool current_bit = a[i] & 1ll<<j;
      if (first_bit != current_bit){
        ans = min(ans,j);
      }
    }
  }
  if (total %2 == 0){
    cout << 0 << "\n";
  }else{
    cout << ans << "\n";
  }
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