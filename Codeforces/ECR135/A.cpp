#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> cnt(n);
  ll maximum = 0;
  ll ans = -1;
  for(int i= 0;i < n;i++){
    scanf("%lld",&cnt[i]);
    if (cnt[i] > maximum){
      maximum = cnt[i];
      ans = i;
    }
  }
  cout << ans + 1<< "\n";
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