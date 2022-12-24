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
#include <climits>
#include <unordered_map>
#include <unordered_set>
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
  ll N,M,E;
  cin >> N >> M >> E;
  UnionFind uf(N+M+1);
  vector<pair<ll,ll>> Edges(E);
  vector<bool> cutted(E,false);
  for(int i = 0;i< E;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    Edges[i] = {u,v};
  }
  ll Q;
  cin >> Q;
  vector<ll> queries(Q);
  for(int i = 0;i < Q;i++){
    ll x;
    cin >> x;
    x--;
    cutted[x] = true;
    queries[i] = x;
  }
  for(int i = 0;i < E;i++){
    if (!cutted[i]){
      uf.unite(Edges[i].first,Edges[i].second);
    }
  }
  for(int i = N;i<N+M;i++){
    uf.unite(i,N+M);
  }
  vector<ll> answers(Q);
  answers[Q-1] = uf.size(N+M)- M-1;
  for(int i = Q-1;i> 0;i--){
    ll x = queries[i];
    uf.unite(Edges[x].first,Edges[x].second);
    answers[i-1] = uf.size(N+M)- M-1;
  }
  for(int i = 0;i < Q;i++){
    cout << answers[i] << "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
