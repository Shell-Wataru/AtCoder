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
  ll n,a,b;
  scanf("%lld", &n);
  scanf("%lld", &a);
  scanf("%lld", &b);
  vector<ll> x(n+1,0);
  for(int i = 1;i <= n;i++){
    cin >> x[i];
  }
  ll current = 0;
  ll ans = 0;
  for(int i = 1;i <= n;i++){
    ans += b* (x[i] - x[current]);
    while(current < i - 1 && ans >= ans + a * (x[current+1] - x[current]) - b * (x[current+1] - x[current]) * (i-current - 1)){
      ans = ans + a * (x[current+1] - x[current]) - b * (x[current+1] - x[current]) * (i-current - 1);
      current++;
    }
  }
  // cout << current << endl;

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
