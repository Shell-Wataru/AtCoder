#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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

class MST
{
  UnionFind uft;

public:
  priority_queue<edge, vector<edge>, greater<edge>> que;
  vector<edge> result;
  ll cost = 0;

  MST(ll node_size, vector<edge> &edges) : uft(node_size)
  {
    for (auto e : edges)
    {
      que.push(e);
    }
    while (!que.empty())
    {
      edge e;
      e = que.top();
      if (!uft.same(e.from, e.to))
      {
        uft.unite(e.from, e.to);
        result.push_back(e);
        cost += e.cost;
        // cout << que.top().from << que.top().to << que.top().cost << std::endl;
      }
      que.pop();
    }
    cout << -cost << endl;
  }
};

ll pow(ll x, ll y, ll modulo)
{
  if (y == 0)
  {
    return 1LL;
  }
  else
  {
    ll y_2 = pow(x, y / 2, modulo) % modulo;
    ll yy = (y_2 * y_2) % modulo;
    if (y % 2 == 0)
    {
      return yy;
    }
    else
    {
      return (yy * x) % modulo;
    }
  }
}
int main()
{
  ll N, M;
  cin >> N >> M;
  vector<edge> edges;
  vector<ll> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      edges.push_back({i, j, -((pow(A[i], A[j], M) + pow(A[j], A[i], M)) % M)});
    }
  }
  MST(N, edges);
  return 0;
}