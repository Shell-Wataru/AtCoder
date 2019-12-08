//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
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
    UnionFind uft(10);
    uft.unite(0,1);
    uft.unite(1,2);
    cout << "0,1 united" << uft.same(0,1) << endl;
    cout << "0,2 united" << uft.same(0,2) << endl;
    cout << "0,9 united" << uft.same(0,9) << endl;
}
