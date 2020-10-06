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
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  ll ans = 1;
  ll height = 1;
  ll total_cells = 1;
  ll total = 1;
  while(total + 2ll * total_cells + (height+1ll) * (height+1ll) <= n){
    ans++;
    total_cells = 2 * total_cells + (height+1ll) * (height+1ll);
    total = total + total_cells;
    height = 2 * height + 1;
  }
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
