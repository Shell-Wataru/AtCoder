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
#include <unordered_map>
using namespace std;
using ll = long long;

struct UnionFind {
  vector< int > data;
  vector<unordered_map<ll,ll>> childrens;
  vector<ll> D;

  UnionFind(int sz) {
    data.assign(sz, -1);
    D = vector<ll>(sz);
    childrens = vector<unordered_map<ll,ll>>(sz);
  }

  void build(){
    for(int i = 0;i < data.size();i++){
      childrens[i][i] = D[i];
    }
  }

  bool unite(int original_x, int original_y, pair<ll,ll> &e,bool force) {
    ll x = find(original_x);
    ll y = find(original_y);
    if(x == y) return (false);
    if (childrens[x].size() == 0 || childrens[y].size() == 0) return false;
    if (force && (childrens[x][original_x] == 0 || childrens[y][original_y] == 0)) return false;
    if(data[x] > data[y]) {
      swap(x, y);
      swap(original_x, original_y);
    }
    data[x] += data[y];
    ll from,to;
    if (force){
      from = original_x;
      to = original_y;
    }else{
      from = childrens[x].begin()->first;
      to = childrens[y].begin()->first;
    }
    e = {from,to};
    D[x]--;
    D[y]--;
    childrens[x][from]--;
    if (childrens[x][from] == 0){
      childrens[x].erase(from);
    }
    childrens[y][to]--;
    if (childrens[y][to] == 0){
      childrens[y].erase(to);
    }
    D[x] += D[y];
    D[y] = 0;
    for(auto p:childrens[y]){
      childrens[x][p.first] = p.second;
    }
    childrens[y].clear();
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
  ll N,M;
  cin >> N >> M;
  UnionFind uf(N);
  ll total = 0;
  bool circle = false;
  for(int i = 0;i < N;i++){
    cin >> uf.D[i];
    total += uf.D[i];
  }
  uf.build();
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    pair<ll,ll> e;
    if (!uf.unite(u,v,e,true)){
      circle =  true;
    }
  }

  if (total != 2*N - 2){
    cout << -1 << endl;
    return 0;
  }

  if (circle){
    cout << -1 << endl;
  }else{
    priority_queue<pair<ll,ll>> current;
    for(int i = 0;i < N;i++){
      if (i == uf.find(i)){
        // cout << i << ":" << uf.D[i] << endl;
        current.emplace(uf.D[uf.find(i)],i);
        if (uf.D[uf.find(i)] <= 0){
            cout << -1 << endl;
            return 0;
        }
      }
    }
    // cout << "!" << endl;
    vector<pair<ll,ll>> additions;
    while(current.size() > 1){
      auto iter_a  = current.top();
      current.pop();
      auto iter_b  = current.top();
      current.pop();
      // cout << iter_a.second <<"," << iter_b.second << endl;
      pair<ll,ll> e;
      if (uf.unite(iter_a.second,iter_b.second,e,false)){
        // cout << uf.find(iter_a.second) << endl;
        current.push({uf.D[uf.find(iter_a.second)],uf.find(iter_a.second)});
        additions.push_back(e);
      }else{
        // cout << "a" << endl;
        // cout << *iter_a <<"," << *iter_b << endl;
        cout << -1 << endl;
        return 0;
      }
    }
    for(auto d:uf.D){
      // cout << d << ",";
      if (d != 0){
        // cout << "b" << endl;
        cout << -1 << endl;
        return 0;
      }
    }
    for(auto e:additions){
      cout << min(e.first,e.second) + 1 << " " << max(e.first,e.second) + 1 << "\n";
    }
    cout << flush;
  }
  return 0;
}
