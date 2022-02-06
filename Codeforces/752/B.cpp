#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll x,y;
  scanf("%lld", &x);
  scanf("%lld", &y);
  if (x == y){
    cout << x << "\n";
  }else if (x > y){
    cout << x + y << "\n";
  }else{
    ll ans = (x+y)/2;
    ll diff = y - ans;
    // cout << diff << endl;
    // cout << diff/x * x << endl;
    ans +=  diff/x * x;
    cout << ans << "\n";
  }
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