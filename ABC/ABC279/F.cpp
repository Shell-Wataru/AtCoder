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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;


struct UnionFind {
  vector< int > data;
  vector< int > box_data;
  vector< bool > contain;

  UnionFind(int sz) {
    data.assign(sz, -1);
    box_data.assign(sz, -1);
    contain.assign(sz, true);
    iota(box_data.begin(),box_data.end(),0);
  }

  bool unite(int base_x, int base_y) {
    ll x = find(base_x);
    ll y = find(base_y);
    box_data[y] = base_x;
    box_data[x] = base_x;
    contain[base_y] = false;
    contain[base_x] = true;
    if(x == y) return (false);
    if(data[x] > data[y]) {
      swap(x,y);
    }
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
  int box(int k){
    return box_data[find(k)];
  }
};

int main()
{
  ll N,Q;
  cin >> N >> Q;
  UnionFind uf(N+Q);
  ll current_balls = N;
  vector<ll> box_names(N+Q);
  vector<ll> inv_box_names(N+Q);
  vector<ll> ball_names(N+Q);
  vector<ll> inv_ball_names(N+Q);
  iota(box_names.begin(),box_names.end(),0);
  iota(ball_names.begin(),ball_names.end(),0);
  iota(inv_box_names.begin(),inv_box_names.end(),0);
  iota(inv_ball_names.begin(),inv_ball_names.end(),0);
  for(int i = 0;i < Q;i++){
    ll t;
    cin >> t;
    if (t == 1){
      ll x,y;
      cin >> x >> y;
      x--;
      y--;
      // cout << "merge:" << inv_box_names[x] << "<-"  << inv_box_names[y] << endl;
      if (uf.contain[inv_box_names[x]] && uf.contain[inv_box_names[y]]){
        uf.unite(inv_box_names[x],inv_box_names[y]);
      }else if (uf.contain[inv_box_names[y]]){
        uf.unite(N+i,inv_box_names[y]);
        box_names[N+i] = x;
        inv_box_names[x] = N+i;
      }

    }else if (t == 2){
      ll x;
      cin >> x;
      x--;
      if (uf.contain[inv_box_names[x]]){
        // cout << "!!" << endl;
        uf.unite(inv_box_names[x],N+i);
        box_names[N+i] = current_balls;
        ball_names[N+i] = current_balls;
        inv_box_names[current_balls] = N+i;
        inv_ball_names[current_balls] = N+i;
      }else{
        box_names[N+i] = x;
        ball_names[N+i] = current_balls;
        inv_box_names[x] = N+i;
        inv_ball_names[current_balls] = N+i;
      }
      // cout << "insert:" << current_balls << "to"  << x << endl;
      current_balls++;
    }else{
      ll x;
      cin >> x;
      x--;
      // cout << x << " is in ";
      // cout << uf.box(inv_ball_names[x]) << "=";
      cout << box_names[uf.box(inv_ball_names[x])] + 1<< endl;
    }
  }
  return 0;
}
