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
  ll x1,y1,z1,x2,y2,z2;
  cin >> x1>>y1>>z1>>x2>>y2>>z2;
  ll ans = 0;
  ll temp = min(z1,y2);
  z1 -= temp;
  y2 -= temp;
  ans += 2 * temp;
  temp = min(y1,x2);
  y1 -= temp;
  x2 -= temp;

  temp = min(y1,y2);
  y1 -= temp;
  y2 -= temp;

  temp = min(y1,z2);
  ans -=  2 * temp;
  cout << ans << endl;
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
  return 0;
}
