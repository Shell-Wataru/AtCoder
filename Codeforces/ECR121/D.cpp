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

ll add(ll x){
  for(int i=0;i<60;i++){
    if (1ll<<i >= x){
      return (1ll<<i) - x;
    }
  }
  return 0;
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  sort(a.begin(), a.end());
  ll ans_x, ans_y;
  ll ans_addition = numeric_limits<ll>::max();
  for (int x = 1; x <= n; x++)
  {
    ll x_index = lower_bound(a.begin(), a.end(), x) - a.begin();
    ll addition = add(x_index) + add(n - x_index) + add(0);
    if (addition < ans_addition){
      ans_addition = addition;
    }
    for (int j = 0; x_index + (1ll << j) < n; j++)
    {
      ll y = a[x_index + (1ll<<j) ];
      ll y_index = lower_bound(a.begin(), a.end(),y) - a.begin();
      ll addition = add(x_index) + add(y_index - x_index) + add(n - y_index);
      if (addition < ans_addition){
        ans_addition = addition;
      }
    }
  }
  cout << ans_addition << endl;
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}