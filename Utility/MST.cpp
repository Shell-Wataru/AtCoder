#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
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
                cout << que.top().from << que.top().to << que.top().cost << std::endl;
            }
            que.pop();
        }
        cout << cost << endl;
    }
};

int main()
{
    vector<ll> nodes{
        1, 2, 3, 4};
    vector<edge> edges{
        {0, 1, 1},
        {0, 2, 1},
        {0, 3, 0},
        {1, 2, 1},
        {1, 3, 0},
        {2, 3, 0},
    };
    MST(4, edges);
}
