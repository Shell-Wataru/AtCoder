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
  vector< int > weights;
  vector< int > max_edge_weights;
  int bad_count = 0;

  UnionFind(int sz) {
    data.assign(sz, -1);
    weights.assign(sz, -1);
    max_edge_weights.assign(sz, -1);
  }

  bool unite(int x, int y,int edge_weight) {
    x = find(x), y = find(y);
    if(x == y) {
      if (max_edge_weights[x] > weights[x]){
        bad_count--;
      }
      max_edge_weights[x] = max(max_edge_weights[x],edge_weight);
      if (max_edge_weights[x] > weights[x]){
        bad_count++;
      }
      return (false);
    }
    if(data[x] > data[y]) swap(x, y);
    if (max_edge_weights[x] > weights[x]){
      bad_count--;
    }
    if (max_edge_weights[y] > weights[y]){
      bad_count--;
    }

    data[x] += data[y];
    weights[x] += weights[y];
    data[y] = x;
    weights[y] = 0;
    max_edge_weights[x] = max(max_edge_weights[x],edge_weight);
    max_edge_weights[x] = max(max_edge_weights[x],max_edge_weights[y]);
    if (max_edge_weights[x] > weights[x]){
      bad_count++;
    }
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
  int weight(int k) {
    return (weights[find(k)]);
  }
};

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  UnionFind uf(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> uf.weights[i];
  }
  priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
  for(int i = 0;i < m;i++){
    ll a,b,y;
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&y);
    a--;
    b--;
    if (uf.same(a,b)){
      if ( y <=  uf.weight(a)){
        uf.unite(a,b,y);
      }else{
        q.push({y,a,b});
      }
    }else{
      if (y <=  uf.weight(a) + uf.weight(b)){
        uf.unite(a,b,y);
      }else{
        q.push({y,a,b});
      }
    }

  }
  ll ans = m;
  while(!q.empty()){
    auto v = q.top();
    q.pop();
    ll a = v[1];
    ll b = v[2];
    ll y = v[0];
    uf.unite(a,b,y);
    if (uf.bad_count == 0){
      ans = min(ans,(ll)q.size());
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
//   cout << flush;
  return 0;
}
