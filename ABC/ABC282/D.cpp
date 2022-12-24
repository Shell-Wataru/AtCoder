#define _USE_MATH_DEFINES
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
#include <unordered_set>
#include <unordered_map>
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
  ll N,M;
  cin >> N >> M;
  UnionFind uf(2*N);
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    uf.unite(2*u,2*v+1);
    uf.unite(2*u+1,2*v);
  }
  map<ll,pair<ll,ll>> counts;

  for(int i = 0;i < N;i++){
    ll a = uf.find(2*i);
    ll b = uf.find(2*i+1);
    if (a == b){
      cout << 0 << endl;
      return 0;
    }

    if (a > b){
      counts[b].second++;
    }else{
      counts[a].first++;
    }
  }
  ll inner = 0;
  ll outer = 0;
  for(auto pp:counts){
    auto p = pp.second;
    // cout << p.first << "," << p.second << endl;
    inner += p.first * p.second;
    outer += (p.first+p.second)*(N-(p.first+p.second));
  }
  // cout << inner << endl;
  cout << inner + outer/2 - M << endl;
  return 0;
}