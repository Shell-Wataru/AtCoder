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

void dfs(vector<vector<ll>> &G, ll current, ll parent, vector<ll> &colors, ll depth)
{
  colors[current] = depth + 1;

  for (auto to : G[current])
  {
    if (to != parent)
    {
      dfs(G, to, current, colors, (depth + 1) % 2);
    }
  }
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> G(n);
  for (int i = 0; i < n - 1; i++)
  {
    ll a, b;
    scanf("%lld", &a);
    scanf("%lld", &b);
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if (n == 2)
  {
    cout << "1 2\n";
    return 0;
  }
  vector<ll> colors(n, 0);
  dfs(G, 0, -1, colors, 0);
  ll total_ones = (n + 2) / 3;
  ll total_twos = (n + 1) / 3;
  ll total_threes = n / 3;
  ll one = 1;
  ll two = 2;
  ll one_count = 0;
  ll two_count = 0;
  for (int i = 0; i < n; i++)
  {
    if (colors[i] == one)
    {
      one_count++;
    }
    else
    {
      two_count++;
    }
  }
  if (two_count > one_count)
  {
    swap(one, two);
    swap(one_count, two_count);
  }
  // for(int i = 0;i < n;i++){
  //   cout << colors[i] << ",";
  // }
  // cout << endl;
  if (one_count >= total_ones && two_count >= total_twos)
  {
    ll one_index = 0;
    ll two_index = 0;
    ll three_index = 1;
    for (int i = 0; i < n; i++)
    {
      if (i != 0)
      {
        cout << " ";
      }
      if (colors[i] == one)
      {
        if (total_ones > 0)
        {
          cout << one_index * 3 + 1;
          one_index++;
          total_ones--;
        }
        else
        {
          cout << three_index * 3;
          three_index++;
        }
      }
      else
      {
        if (total_twos > 0)
        {
          cout << two_index * 3 + 2;
          two_index++;
          total_twos--;
        }
        else
        {
          cout << three_index * 3;
          three_index++;
        }
      }
    }
    cout << "\n";
  }else{
    ll one_index = 0;
    ll two_index = 0;
    ll three_index = 1;
    for (int i = 0; i < n; i++)
    {
      if (i != 0)
      {
        cout << " ";
      }
      if (colors[i] == one)
      {
        if (total_ones > 0)
        {
          cout << one_index * 3 + 1;
          one_index++;
          total_ones--;
        }
        else if (total_twos > 0)
        {
          cout << two_index * 3 + 2;
          two_index++;
          total_twos--;
        }
        else
        {
          cout << three_index * 3;
          three_index++;
        }
      }
      else
      {
        cout << three_index * 3;
        three_index++;
      }
    }
    cout << "\n";
  }
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