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
    // 整数の入力
    ll N;
    cin >> N;
    UnionFind uf(N);
    vector<vector<ll>> X(100000,vector<ll>());
    vector<vector<ll>> Y(100000,vector<ll>());
    vector<pair<ll,ll>> P(N);
    for(int i = 0;i < N;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        X[x].push_back(i);
        Y[y].push_back(i);
        P[i] = {x,y};
    }
    // cout << "!" << endl;
    for(int i = 0;i < 100000;i++){
        for(int j = 1;j < X[i].size();j++){
            uf.unite(X[i][j],X[i][j-1]);
        }
        for(int j = 1;j < Y[i].size();j++){
            uf.unite(Y[i][j],Y[i][j-1]);
        }
    }
    // cout << "!!" << endl;
    ll count = 0;
    map<ll,set<ll>> xs;
    map<ll,set<ll>> ys;
    for(int i = 0;i < N;i++){
        ll representative = uf.find(i);
        xs[representative].insert(P[i].first);
        ys[representative].insert(P[i].second);
    }
    for(auto p:xs){
        count += p.second.size() * ys[p.first].size();
    }
    cout << count - N << endl;
    return 0;
}