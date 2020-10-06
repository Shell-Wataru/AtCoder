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
  ll n, k, l;
  cin >> n >> k >> l;
  vector<ll> depths(n + 1, 0);
  for (size_t i = 1; i <= n; i++)
  {
    scanf("%lld", &depths[i]);
  }
  vector<ll> p(2 * k);
  for (int i = 0; i < k; i++)
  {
    p[i] = i;
    // cout << " " <<p[i];
  }
  for (int i = 0; i < k; i++)
  {
    p[i + k] = k - i;
    // cout << " " <<p[i+k];
  }
  // cout << endl;

  vector<vector<bool>> can_go(n + 1, vector<bool>(2 * k, false));

  for (int i = 0; i <= n; i++)
  {
    for (ll j = 0; j < 2 * k; j++)
    {
      if (i == 0)
      {
        can_go[i][j] = true;
      }
      else if (can_go[i - 1][(j - 1 + 2 * k) % (2 * k)] && depths[i] + p[j] <= l)
      {
        can_go[i][j] = true;
      }
    }
    for (ll j = 0; j < 2 * k; j++)
    {
      if (i == 0)
      {
        can_go[i][j] = true;
      }
      else if (can_go[i][(j - 1 + 2 * k) % (2 * k)] && depths[i] + p[j] <= l)
      {
        can_go[i][j] = true;
      }
    }
    for (ll j = 0; j < 2 * k; j++)
    {
      if (i == 0)
      {
        can_go[i][j] = true;
      }
      else if (can_go[i][(j - 1 + 2 * k) % (2 * k)] && depths[i] + p[j] <= l)
      {
        can_go[i][j] = true;
      }
    }
  }
  bool can = false;
  for (ll j = 0; j < 2 * k; j++)
  {
    if (can_go[n][j])
    {
      can = true;
    }
  }
  if (can){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
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
