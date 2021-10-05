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
  vector<map<ll,ll>> class_count;
  ll t;
  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    for(auto p:class_count[y]){
        class_count[x][p.first] += p.second;
    }
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
    UnionFind uf(N);
    uf.class_count = vector<map<ll,ll>>(N);
    for(int i = 0;i < N;i++){
        ll c;
        cin >> c;
        c--;
        uf.class_count[i][c] = 1;
    }
    for(int i = 0;i < Q;i++){
        ll t,a,b;
        cin >> t >> a >> b;
        if (t == 1){
            a--;
            b--;
            uf.unite(a,b);
        }else{
            a--;b--;
            cout << uf.class_count[uf.find(a)][b] << "\n";
        }
    }
    cout << flush;
    return 0;
}