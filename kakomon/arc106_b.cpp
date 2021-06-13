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

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<ll> a(N);
    vector<ll> b(N);
    vector<ll> a_total(N,0);
    vector<ll> b_total(N,0);
    UnionFind uf(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        uf.unite(u,v);
    }
    for(int i = 0;i < N;i++){
        a_total[uf.find(i)] += a[i];
        b_total[uf.find(i)] += b[i];
    }

    bool is_ok = true;
    for(int i = 0;i < N;i++){
        if (a_total[i] != b_total[i]){
            is_ok = false;
        }
    }
    if (is_ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}