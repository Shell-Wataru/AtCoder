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
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n, m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<set<ll>> G(n);
  ll ans = n;
  for (int i = 0; i < m; i++)
  {
    ll a, b;
    scanf("%lld", &a);
    scanf("%lld", &b);
    a--;
    b--;
    if (a < b)
    {
      G[a].insert(b);
      if (G[a].size() == 1)
      {
        ans--;
      }
    }
    else
    {
      G[b].insert(b);
      if (G[b].size() == 1)
      {
        ans--;
      }
    }
  }
  // cout << "before:" << ans << endl;
  ll q;
  scanf("%lld", &q);
  for (int i = 0; i < q; i++)
  {
    ll t;
    scanf("%lld", &t);
    if (t == 1)
    {
      ll a, b;
      scanf("%lld", &a);
      scanf("%lld", &b);
      a--;
      b--;
      if (a < b)
      {
        G[a].insert(b);
        if (G[a].size() == 1)
        {
          ans--;
        }
      }
      else
      {
        G[b].insert(a);
        if (G[b].size() == 1)
        {
          ans--;
        }
      }
    }
    else if (t == 2)
    {
      ll a, b;
      scanf("%lld", &a);
      scanf("%lld", &b);
      a--;
      b--;
      if (a < b)
      {
        G[a].erase(b);
        if (G[a].size() == 0)
        {
          ans++;
        }
      }
      else
      {
        G[b].erase(a);
        if (G[b].size() == 0)
        {
          ans++;
        }
      }
    }
    else
    {
      cout << ans << "\n";
    }
  }

  return 0;
}

int main()
{
  // // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
