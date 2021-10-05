#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> next_same_index(n, numeric_limits<ll>::max());
  vector<ll> last_occur(n + 1, -1);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    if (last_occur[a[i]] != -1)
    {
      next_same_index[last_occur[a[i]]] = i;
    }
    last_occur[a[i]] = i;
  }
  ll ans = 0;
  ll white_next_same_index = numeric_limits<ll>::max();
  ll black_next_same_index = numeric_limits<ll>::max();
  for (int i = 0; i < n; i++)
  {
    bool add_to_white;
    if (i == white_next_same_index)
    {
      add_to_white = true;
    }
    else if (i == black_next_same_index)
    {
      add_to_white = false;
    }
    else if (white_next_same_index > black_next_same_index)
    {
      add_to_white = true;
    }
    else
    {
      add_to_white = false;
    }
    if (add_to_white)
    {
      if (i != white_next_same_index)
      {
        ans++;
      }
      white_next_same_index = next_same_index[i];
    }
    else
    {
      if (i != black_next_same_index)
      {
        ans++;
      }
      black_next_same_index = next_same_index[i];
      ;
    }
  }
  cout << ans << endl;
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}
