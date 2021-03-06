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

int main(){
    ll N,M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<ll> p(N);
    for(int i = 0;i <N;i++){
        cin >> p[i];
        p[i]--;
    }
    for (size_t i = 0; i < M; i++)
    {
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x,y);
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        if (uf.same(i,p[i])){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;

}