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

ll dfs1(vector<vector<ll>> &G, vector<bool> &c, vector<ll> &data1, ll current, ll parent)
{
  ll ret = 0;
  for (auto to : G[current])
  {
    if (to != parent)
    {
      ret = max(ret, dfs1(G, c, data1, to, current));
    }
  }
  if (c[current])
  {
    ret++;
  }
  return ret;
}

void dfs2(vector<vector<ll>> &G, vector<bool> &c, vector<ll> &data1, vector<ll> &data2, ll current, ll parent, ll d_parent)
{
  vector<pair<ll, ll>> d_child;
  for (auto to : G[current])
  {
    if (to == parent)
      d_child.emplace_back(d_parent, to);
    else
      d_child.emplace_back(data1[to], to);
  }
  sort(d_child.rbegin(), d_child.rend());
  data2[current] = d_child[0].first;
  for (auto to : G[current])
  {
    if (to != parent)
    {
      if (d_child[0].second == to)
      {
        dfs2(G, c, data1, data2, to, current, d_child[1].first);
      }
      else
      {
        dfs2(G, c, data1, data2, to, current, d_child[0].first);
      }
    }
  }
}

int solve()
{
  ll n, m;
  scanf("%lld", &n);
  vector<bool> c(n);
  vector<vector<ll>> G(n);
  for (int i = 0; i < n; i++)
  {
    ll cc;
    scanf("%lld", &cc);
    c[i] = cc == 1;
  }
  for (int i = 0; i < n - 1; i++)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> data1(n);
  cout << "!!" << endl;
  vector<ll> data2(n);
  cout << "!!" << endl;
  dfs1(G, c, data1, 0, -1);
  dfs2(G, c, data1, data2, 0, -1, 0);
  for (int i = 0; i < n; i++)
  {
    if (data2[i] >= 2 || c[i])
    {
      cout << 1 << " ";
    }
    else
    {
      bool found = false;
      for (auto to : G[i])
      {
        if (c[to])
        {
          found = true;
          break;
        }
      }
      if (found)
      {
        cout << "1 ";
      }
      else
      {
        cout << "0 ";
      }
    }
  }
  cout << "\n";
  return 0;
}
int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}