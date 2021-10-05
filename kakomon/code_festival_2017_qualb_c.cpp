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

template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}
struct fast_ios
{
    fast_ios()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

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
    UnionFind uf(2*N);
    for(int i = 0;i < M;i++){
      ll u,v;
      cin >> u >> v;
      u--;
      v--;
      uf.unite(2*u,2*v+1);
      uf.unite(2*u+1,2*v);
    }
    bool is_bipartile = true;
    ll white_count = 0;
    ll black_count = 0;
    for(int i = 0;i < N;i++){
      if (uf.same(2*i,2*i+1)){
        is_bipartile = false;
      }
      if (uf.same(0,2*i)){
        white_count++;
      }else{
        black_count++;
      }
    }

    if (is_bipartile){
      cout << white_count*black_count - M << endl;
    }else{
      cout << N*(N-1)/2 - M << endl;
    }
   return 0;
}