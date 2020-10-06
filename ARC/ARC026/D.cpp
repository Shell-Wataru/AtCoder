#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

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

struct edge{
  ll from,to,cost,time;
};

double solve(ll N,vector<edge> &edges, double l, double r){
  if (r - l < 1e-8){
    return r;
  }
  double center = (l+r)/2;
  UnionFind uf(N);
  sort(edges.begin(),edges.end(),[center](edge &a,edge &b){
    return a.cost - a.time * center < b.cost - b.time * center;
  });

  double total_cost = 0;
  for(auto &e:edges){
    double cost = e.cost - e.time * center;
    if(uf.unite(e.from,e.to) || cost < 0){
      total_cost += cost;
    }
  }
  if (total_cost > 0){
    return solve(N,edges, center,r);
  }else{
    return solve(N,edges, l, center);
  }
}

int main()
{
  // 整数の入力
  ll N, M;
  cin >> N >> M;
  vector<edge> edges(M);
  for (int i = 0; i < M; i++)
  {
    ll a, b, c ,d;
    cin >> a >> b >> c >> d;
    edges[i] = {a, b, c, d};
  }
  cout << fixed << setprecision(12) <<solve(N,edges,0,1e9) << endl;
 return 0;
}