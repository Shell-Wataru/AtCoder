#include<iostream>
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
    vector<vector<pair<ll,ll>>> edges(N);
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        edges[min(u,v)].push_back({u,v});
    }
    vector<ll> ans(N);
    ll count = 0;
    UnionFind uf(N);
    for(int i = N-1;i >= 0;i--){
        ans[i] = count;
        count++;
        for(auto e:edges[i]){
            if (uf.unite(e.first,e.second)){
                count--;
            }
        }
    }
    for(int i = 0;i < N;i++){
        cout << ans[i] << "\n";
    }
    cout << flush;
    return 0;
}