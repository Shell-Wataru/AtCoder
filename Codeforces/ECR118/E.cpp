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

vector<pair<ll, ll>> directions = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};
int solve()
{

  ll n, m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<string> G(n);
  for (int i = 0; i < n; i++)
  {
    cin >> G[i];
  }
  ll Lx, Ly;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (G[i][j] == 'L')
      {
        Lx = i;
        Ly = j;
        break;
      }
    }
  }
  queue<pair<ll, ll>> q;
  q.push({Lx, Ly});

  while (!q.empty())
  {
    ll x = q.front().first;
    ll y = q.front().second;
    q.pop();
    for (auto d1 : directions)
    {
      ll next_x = x + d1.first;
      ll next_y = y + d1.second;
      if (0 <= next_x && next_x < n &&
          0 <= next_y && next_y < m &&
          G[next_x][next_y] == '.')
      {
        ll free = 0;
        for (auto d2 : directions)
        {
          ll next_neigbour_x = next_x + d2.first;
          ll next_neigbour_y = next_y + d2.second;
          if (0 <= next_neigbour_x && next_neigbour_x < n &&
              0 <= next_neigbour_y && next_neigbour_y < m &&
              G[next_neigbour_x][next_neigbour_y] == '.')
          {
            free++;
          }
        }
        if (free <= 1){
          G[next_x][next_y] = '+';
          q.push({next_x,next_y});
        }
      }
    }
  }
  for(int i = 0;i < n;i++){
    cout << G[i] << "\n";
  }
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