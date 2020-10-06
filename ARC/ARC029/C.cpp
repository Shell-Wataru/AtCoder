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
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

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
                // cout << que.top().from << que.top().to << que.top().cost << std::endl;
            }
            que.pop();
        }
        // cout << cost << endl;
    }
};

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<edge> edges;
    for(int i = 0;i < N;i++){
        ll c;
        cin >> c;
        edges.push_back({0,i+1,c});
    }

    for(int i = 0;i < M;i++){
        ll from,to,cost;
        cin >> from >> to >> cost;
        edges.push_back({from,to,cost});
    }
    MST mst(N+1,edges);
    cout << mst.cost << endl;
    return 0;
}