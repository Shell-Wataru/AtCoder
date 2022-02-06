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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll a,b;
  scanf("%lld", &a);
  scanf("%lld", &b);
  ll base = 0;
  while(b >= 1ll<<(base)){
    base++;
  }
  ll ans = b-a;
  for(int i = a;i <= b;i++){
    ll take = i-a;
    for(ll j = 0;j < 25;j++){
      if ((i & 1ll<<j) && !(b & 1ll<<j)){
        take += 1ll<<j;;
      }
    }
    take++;
    ans = min(ans,take);
  }
  cout << ans << endl;
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
