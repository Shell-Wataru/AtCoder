#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
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


int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  UnionFind uf(2*n);
  for(int i = 0;i < m;i++){
    ll u,v;
    scanf("%lld",&u);
    scanf("%lld",&v);
    string c;
    cin >> c;
    u--;v--;
    if (c == "imposter"){
      uf.unite(2*u,2*v+1);
      uf.unite(2*u+1,2*v);
    }else{
      uf.unite(2*u,2*v);
      uf.unite(2*u+1,2*v+1);
    }
  }
  bool can_make = true;
  ll maximum_imposters = 0;
  map<ll,pair<ll,ll>>  counts;
  for(int i = 0;i < n;i++){
    if (uf.same(2*i,2*i+1)){
      can_make = false;
      break;
    }else if(uf.find(2*i) % 2 == 0){
      counts[uf.find(2*i)].first++;
    }else if(uf.find(2*i+1) % 2 == 0){
      counts[uf.find(2*i+1)].second++;
    }
  }
  if (can_make){
    ll ans = 0;
    for(auto p:counts){
      ans += max(p.second.first,p.second.second);
    }
    cout << ans << "\n";
  }else{
    cout << -1 << "\n";
  }
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}
