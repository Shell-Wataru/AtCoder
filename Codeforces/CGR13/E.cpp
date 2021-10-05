#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

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


int solve()
{

    ll n;
    scanf("%lld",&n);
    vector<vector<ll>> G(n);
    for(int i = 0;i < n;i++){
      ll u,v;
      scanf("%lld",&u);
      scanf("%lld",&v);
      u--;v--;
      G[u].push_back(u);
      G[v].push_back(u);
    }
    queue<ll> q;
    for (size_t i = 0; i < n; i++)
    {
      if (G[i].size() == 1){
        q.push(i);
      }
    }
    UnionFind uf(n);
    vector<ll> fibs(102);
    fibs[0] = 1;
    fibs[1] = 1;
    for (size_t i = 0; i < 100; i++)
    {
      fibs[i+2] = fibs[i+1] + fibs[i];
      cout << fibs[i+2] << endl;
    }

    for (size_t i = 0; i < 100; i++)
    {
      while(!q.empty()){
        uf.
      }
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
    // cout << flush;
    return 0;
}