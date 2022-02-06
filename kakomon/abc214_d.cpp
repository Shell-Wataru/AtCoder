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


int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> edges(N,vector<ll>(3));
    for(int i = 0;i < N-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i][0] = w;
        edges[i][1] = u;
        edges[i][2] = v;
    }
    sort(edges.begin(),edges.end());
    UnionFind uf(N);
    ll ans = 0;
    for(int i = 0;i < N;i++){
        ll u = edges[i][1];
        ll v = edges[i][2];
        ll w = edges[i][0];
        ans += w*uf.size(u)*uf.size(v);
        uf.unite(u,v);
    }
    cout << ans << endl;
    return 0;
}