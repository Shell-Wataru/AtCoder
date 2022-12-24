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
  ll N,M;
  cin >> N >> M;
  vector<vector<vector<ll>>> G(N);
  UnionFind uf(N);
  for(int i = 0;i < M;i++){
    ll u,v,c;
    cin >> u >> v >> c;
    u--;
    v--;
    G[u].push_back({c,v,i});
    G[v].push_back({c,u,i});
  }
  priority_queue<vector<ll>,vector<vector<ll>>, greater<vector<ll>>> q;
  for(auto p:G[0]){
    q.push(p);
  }
  vector<ll> answers;
  vector<ll> distances(N,numeric_limits<ll>::max());
  distances[0] = 0;
  while(!q.empty()){
    auto v = q.top();
    ll d = v[0];
    ll current = v[1];
    ll index = v[2];
    q.pop();
    if (d < distances[current]){
      distances[current] = d;
      answers.push_back(index);
      for(auto p:G[current]){
        q.push({p[0]+d,p[1],p[2]});
      }
    }
  }
  for(auto i:answers){
    cout << i + 1 << " ";
  }
  cout << endl;
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
