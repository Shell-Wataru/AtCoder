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
#include <stack>

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
  ll N;
  cin >> N;
  map<pair<ll,ll>,ll> mapping;
  for(int i = 0;i < N;i++){
    ll x,y;
    cin >> x >> y;
    mapping[{x,y}] = i;
  }
  UnionFind uf(N);
  for(auto pp:mapping){
    auto p   = pp.first;
    auto index = pp.second;
    if (mapping.count({p.first+1,p.second})){
      uf.unite(index,mapping[{p.first+1,p.second}]);
    }
    if (mapping.count({p.first,p.second+1})){
      uf.unite(index,mapping[{p.first,p.second+1}]);
    }
    if (mapping.count({p.first+1,p.second+1})){
      uf.unite(index,mapping[{p.first+1,p.second+1}]);
    }
  }
  ll ans = 0;
  for(auto i = 0;i < N;i++){
    if (uf.find(i) == i){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
