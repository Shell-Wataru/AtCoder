#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
#include <stack>

using namespace std;
using ll = long long;

// https://ei1333.github.io/luzhiled/snippets/graph/chu-liu-edmond.html
template <typename T>
struct edge
{
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x)
  {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

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

template <typename T>
struct MinimumSpanningTreeArborescence
{
  T INF;
  vector<vector<T>> G;
  const int V;
  MinimumSpanningTreeArborescence(int V) : INF(numeric_limits<T>::max()), V(V), G(V, vector<T>(V, INF)) {}

  T build(int start)
  {
    UnionFind uf(V);
    vector<int> used(V, -1);
    used[start] = start;

    T ret = 0;
    for (int s = 0; s < V; s++)
    {
      stack<int> path;
      for (int u = s; used[u] < 0;)
      {
        auto itr = min_element(G[u].begin(), G[u].end());
        T cost = *itr;
        ret += cost;
        if (cost != 0)
        {
          for (int i = 0; i < V; i++)
          {
            if (G[u][i] != INF)
            {
              G[u][i] -= cost;
            }
          }
        }
        *itr = INF;
        path.push(u);
        used[u] = s;
        int v = uf.find(itr - G[u].begin());
        if (used[v] == s)
        {
          int w;
          vector<T> nextEdges(V, INF);
          do
          {
            w = path.top();
            path.pop();
            for (int i = 0; i < V; i++)
            {
              nextEdges[i] = min(nextEdges[i], G[w][i]);
            }
          } while (uf.unite(v, w));
          int root = uf.find(v);
          for (int i = 0; i < V; i++)
          {
            if (uf.same(root, i))
            {
              G[root][i] = INF;
            }
            else
            {
              G[root][i] = nextEdges[i];
            }
          }

          used[root] = -1;
        }
        u = uf.find(v);
      }
    }
    return ret;
  }
};

int main()
{
  ll N = 5000;
  // MinimumSpanningTreeArborescence<int> msta(N);
  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j < N; j++)
  //   {
  //     if (i == j)
  //     {
  //       continue;
  //     }
  //     msta.G[i][j] = 1;
  //   }
  // }

  // cout << msta.build(N - 1) << endl;
  // cout << msta.build(0) << endl;

  vector<vector<int>> edges{
      {0, 1, 1},
      {0, 2, 1},
      {0, 3, 0},
      {1, 2, 1},
      {1, 3, 0},
      {2, 3, 0},
  };
  MinimumSpanningTreeArborescence<int> msta(5000);
  cout << msta.build(0) << endl;
  return 0;
}
