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
  vector<priority_queue<pair<ll,ll>> > childrens;
  set<ll> current;
  vector<ll> D;
  UnionFind(int sz) {
    data.assign(sz, -1);
    D = vector<ll>(sz);
    childrens = vector<priority_queue<pair<ll,ll>> >(sz);
  }

  void build(){
    for(int i = 0;i < data.size();i++){
      childrens[i].push({D[i],i});
      current.insert(i);
    }
  }

  bool unite(int x, int y, pair<ll,ll> &e) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if (childrens[x].size() == 0 || childrens[y].size() == 0) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    current.erase(y);
    auto x_top = childrens[x].top();
    auto y_top = childrens[y].top();
    childrens[x].pop();
    childrens[y].pop();
    e = {x_top.second,y_top.second};
    D[x]--;
    D[y]--;
    if (x_top.first > 1){
      childrens[x].push({x_top.first -1 , x_top.second});
    }
    if (y_top.first > 1){
      childrens[y].push({y_top.first -1 , y_top.second});
    }

    while(!childrens[y].empty()){
      childrens[x].push(childrens[y].top());
      D[x] += D[childrens[y].top().second];
      D[childrens[y].top().second] = 0;
      childrens[y].pop();
    }
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
  vector<ll> D(N);
  UnionFind uf(N);
  ll total = 0;
  bool circle = false;
  for(int i = 0;i < N;i++){
    cin >> uf.D[i];
  }
  uf.build();
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    pair<ll,ll> e;
    circle =  circle || !uf.unite(u,v,e);
  }
  if (circle){
    cout << -1 << endl;
  }else{
    priority_queue<pair<ll,ll>> current;
    for(int i = 0;i < N;i++){
      if (i == uf.find(i)){
        current.emplace(uf.D[uf.find(i)],i);
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
      if (uf.unite(iter_a.second,iter_b.second,e)){
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
      cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
    cout << flush;
  }
  return 0;
}
