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
  ll l, r, m;
  cin >> l >> r >> m;
  ll min_diff = BASE_NUM;
  ll min_diff_a = -1;
  ll diff = 0;
  ll ans_n = 0;
  for (int i = l; i <= r; i++)
  {
    ll n = m / i;
    if (n > 0 && abs(m - n * i) < min_diff)
    {
      min_diff = abs(m - n * i);
      min_diff_a = i;
      diff = m - n * i;
      ans_n = n;
    }
    if (abs(m - (n + 1) * i) < min_diff)
    {
      min_diff = abs(m - (n + 1) * i);
      min_diff_a = i;
      diff = m - (n + 1) * i;
      ans_n = n+1;
    }
  }

  if (diff >= 0){
    cout << min_diff_a << " " << r << " " << r - diff << endl;
  }else{
    cout << min_diff_a << " " << r + diff << " " << r << endl;
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
  return 0;
}
