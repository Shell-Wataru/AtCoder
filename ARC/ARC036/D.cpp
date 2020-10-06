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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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
  // 整数の入力
  ll N,Q;
  cin >> N >> Q;
  vector<ll> connected(N,-1);
  vector<bool> contains_odd_loop(N,false);
  UnionFind uf(N);
  for(int i = 0;i < Q;i++){
    ll w,x,y,z;
    cin >> w >> x >> y >> z;
    x--;
    y--;
    if (w == 1){
      bool x_odds_loop = contains_odd_loop[uf.find(x)];
      bool y_odds_loop = contains_odd_loop[uf.find(y)];
      ll x_connected = connected[uf.find(x)];
      ll y_connected = connected[uf.find(y)];
      if (x_odds_loop || y_odds_loop){
        if (x_connected != -1){
          uf.unite(x,x_connected);
        }
        if(y_connected != -1){
          uf.unite(y,y_connected);
        }
        uf.unite(x,y);
        contains_odd_loop[uf.find(x)] = true;
      }else if (z % 2 == 0){
        uf.unite(x,y);
        if (x_connected != -1 && y_connected != -1){
          uf.unite(x_connected,y_connected);
        }else if (x_connected != -1){
          connected[uf.find(x)] = x_connected;
        }else if(y_connected != -1){
          connected[uf.find(x)] = y_connected;
        }
      }else{
        if (uf.same(uf.find(x),uf.find(y))){
          if (x_connected != -1){
            uf.unite(uf.find(x),x_connected);
          }
          contains_odd_loop[uf.find(x)] = true;
        }else{
          if (x_connected == -1){
            connected[uf.find(x)] = uf.find(y);
            x_connected = uf.find(y);
          }
          if (y_connected == -1){
            connected[uf.find(y)] = uf.find(x);
            y_connected = uf.find(x);
          }
          uf.unite(uf.find(x),y_connected);
          uf.unite(uf.find(y),x_connected);
        }
      }
    }else{
      if (uf.same(x,y)){
        cout << "YES" << "\n";
      }else{
        cout << "NO" << "\n";
      }
    }
  }
  cout << flush;

  return 0;
}