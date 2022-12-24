#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
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
        if (result.size() != node_size - 1){
            cost = numeric_limits<ll>::max();
        }
    }
};

ll costNoAirNoSea(ll N,vector<edge> E){
    MST mst(N,E);
    return mst.cost;
}

ll costAirNoSea(ll N,vector<ll> &X,vector<edge> E){
    for(int i = 0;i < N;i++){
        E.push_back({i,N,X[i]});
    }
    MST mst(N+1,E);
    return mst.cost;
}
ll costAirSea(ll N,vector<ll> &X,vector<ll> &Y,vector<edge> E){
    for(int i = 0;i < N;i++){
        E.push_back({i,N,X[i]});
    }
    for(int i = 0;i < N;i++){
        E.push_back({i,N+1,Y[i]});
    }
    MST mst(N+2,E);
    return mst.cost;
}
int solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> X(n);
  vector<ll> Y(n);
  for(int i = 0;i < n;i++){
    cin >> X[i];
  }
  for(int i = 0;i < n;i++){
    cin >> Y[i];
  }
  vector<edge> E(m);
  for(int i = 0;i < m;i++){
    ll u,v,c;
    cin >> u >> v >> c;
    u--;v--;
    E[i] = {u,v,c};
  }
  ll ans = numeric_limits<ll>::max();
  ans = min(ans,costNoAirNoSea(n,E));
  ans = min(ans,costAirNoSea(n,X,E));
  ans = min(ans,costAirNoSea(n,Y,E));
  ans = min(ans,costAirSea(n,X,Y,E));
  cout << ans << "\n";
  return 0;
}

int main()
{
  // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}