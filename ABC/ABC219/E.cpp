#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

struct UnionFind
{
  vector<int> data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y)
  {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k)
  {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

class edge
{
public:
  ll from, to, cost;
  bool operator<(const edge &another) const
  {
    return cost < another.cost;
  };

  bool operator>(const edge &another) const
  {
    return cost > another.cost;
  };
};

int main()
{
  vector<vector<ll>> A(4, vector<ll>(4));
  ll representative = -1;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> A[i][j];
      if (A[i][j] == 1)
      {
        representative = 6 * (i+1) + j + 1;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < 1ll << 16; i++)
  {
    bool is_ok = true;
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        if (A[j][k] == 1 && !(i & 1ll << (4 * j + k)))
        {
          is_ok = false;
        }
      }
    }
    if (!is_ok){
      continue;
    }
    UnionFind uf(36);
    vector<vector<ll>> G(6,vector<ll>(6,0));

    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        if ((i & 1ll << (4 * j + k)))
        {
          G[j+1][k+1] = 1;
        }
      }
    }
    for (int j = 0; j < 6; j++)
    {
      for (int k = 0; k < 6; k++)
      {
        if (j + 1 < 6 && G[j][k] == G[j+1][k])
        {
          uf.unite(6 * j + k, 6 * (j + 1) + k);
        }
        if (k + 1 < 6 && G[j][k] == G[j][k+1])
        {
          uf.unite(6 * j + k, 6 * j + k + 1);
        }
      }
    }

    for (int j = 0; j < 6; j++)
    {
      for (int k = 0; k < 6; k++)
      {
        if (G[j][k] == 1 && !uf.same(representative, 6 * j + k))
        {
            is_ok = false;
        }
        if (G[j][k] == 0 && !uf.same(0, 6 * j + k))
        {
            is_ok = false;
        }
      }
    }
    if (is_ok)
    {
    //   cout << "=====" << endl;
    //   for (int j = 0; j < 6; j++)
    // {
    //   for (int k = 0; k < 6; k++)
    //   {
    //       cout << G[j][k];
    //   }
    //   cout << endl;
    // }
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
