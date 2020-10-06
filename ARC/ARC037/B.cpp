#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

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
    ll N,M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<pair<ll,ll>> edges;
    for (size_t i = 0; i < M; i++)
    {
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x,y);
        edges.push_back({x,y});
    }
    map<ll,ll> tree_edges;
    for(auto p:edges){
        tree_edges[uf.find(p.first)]++;
    }
    ll remain = N;
    ll ans = 0;
    for(auto p:tree_edges){
        remain -= uf.size(p.first);
        if (p.second == uf.size(p.first) - 1){
            ans++;
        }
    }
    cout << ans + remain << endl;
    return 0;
}