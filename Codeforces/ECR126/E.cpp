#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
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

template <typename T>
struct Compress
{
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs)
    {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs)
    {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x)
    {
        xs.emplace_back(x);
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const
    {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
                  { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const
    {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    size_t size() const
    {
        return xs.size();
    }
    const T &operator[](int k) const
    {
        return xs[k];
    }
};

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
// 全体が1
template< typename Monoid >
struct SegmentTree {
  using T = typename Monoid::T;

  int sz;
  vector< T > seg;
  const T id = Monoid::id();

  SegmentTree(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, id);
  }

  void set(int k, const T &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T query(int a, int b) {
    T L = id, R = id;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = Monoid::op(L, seg[a++]);
      if(b & 1) R = Monoid::op(seg[--b], R);
    }
    return Monoid::op(L, R);
  }

  T operator[](const int &k) const {
    return seg[k + sz];
  }

  int find_subtree(int a, T &x, T &M, bool type) {
    while(a < sz) {
      T nxt = type ? seg[2 * a + type] : seg[2 * a + type];
      if(Monoid::check(nxt,x)) a = 2 * a + type;
      else M = nxt,a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  // 条件を満たす[a,b]で最もbが前方にあるもの
  int find_first(int a, T x) {
    T L = id;
    if(a <= 0) {
      if(Monoid::check(seg[1],x)) return find_subtree(1, x, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        T nxt = Monoid::op(L, seg[a]);
        if(Monoid::check(seg[a],x)) return find_subtree(a, x, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  // 条件を満たす[a,b)で最もaが後方にあるもの
  int find_last(int b, T x) {
    T R = id;
    if(b >= sz) {
      if(Monoid::check(seg[1],x)) return find_subtree(1, x, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        T nxt = Monoid::op(seg[--b], R);
        if(Monoid::check(nxt,x)) return find_subtree(b, x, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct D{
  vector<ll> l;
  vector<ll> r;
  ll components = 0;
};

struct monoid
{
  using T = D;
  static T op(T l, T r) {
    ll new_components  = l.components + r.components;
    UnionFind uf(9);
    for(int i = 0;i < 3;i++){
      if (r.l[i] != 0){
        r.l[i] += 4;
      }
      if (r.r[i] != 0){
        r.r[i] += 4;
      }
    }
    for(int i = 0;i < 3;i++){
      if (l.r[i] != 0 && r.l[i] != 0){
        if (uf.unite(l.r[i],r.l[i])){
          new_components--;
        }
      }
    }
    vector<ll> used(9);
    used[0] = true;
    for(int i = 0;i < 3;i++){
      used[uf.find(l.l[i])] = true;
      used[uf.find(r.r[i])] = true;
    }
    vector<ll> indices(9);
    ll index = 0;
    for(int i = 0;i < 9;i++){
      if (used[i]){
        indices[i] = index;
        index++;
      }
    }
    vector<ll> new_l(3);
    vector<ll> new_r(3);
    for(int i = 0;i < 3;i++){
      new_l[i] = indices[uf.find(l.l[i])];
      new_r[i] = indices[uf.find(r.r[i])];
    }
    return {
      new_l,
      new_r,
      new_components
    };
  }
  static const T id() {
    return {
      {0,0,0},
      {0,0,0},
      0
    };
  }

  static const bool check(T &current, T &x) {
    return true;
  }
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<string> S(3);
  cin >> S[0];
  cin >> S[1];
  cin >> S[2];
  SegmentTree<monoid> seg(n);
  for(int i = 0;i < n;i++){
    if (S[0][i] == '0' && S[1][i] == '0' && S[2][i] == '0'){
      seg.set(i,{
        {0,0,0},
        {0,0,0},
        0
      });
    }else if (S[0][i] == '0' && S[1][i] == '0' && S[2][i] == '1'){
      seg.set(i,{
        {0,0,1},
        {0,0,1},
        1
      });
    }else if (S[0][i] == '0' && S[1][i] == '1' && S[2][i] == '0'){
      seg.set(i,{
        {0,1,0},
        {0,1,0},
        1
      });
    }else if (S[0][i] == '0' && S[1][i] == '1' && S[2][i] == '1'){
      seg.set(i,{
        {0,1,1},
        {0,1,1},
        1
      });
    }else if (S[0][i] == '1' && S[1][i] == '0' && S[2][i] == '0'){
      seg.set(i,{
        {1,0,0},
        {1,0,0},
        1
      });
    }else if (S[0][i] == '1' && S[1][i] == '0' && S[2][i] == '1'){
      seg.set(i,{
        {1,0,2},
        {1,0,2},
        2
      });
    }else if (S[0][i] == '1' && S[1][i] == '1' && S[2][i] == '0'){
      seg.set(i,{
        {1,1,0},
        {1,1,0},
        1
      });
    }else if (S[0][i] == '1' && S[1][i] == '1' && S[2][i] == '1'){
      seg.set(i,{
        {1,1,1},
        {1,1,1},
        1
      });
    }
  }
  seg.build();
  ll q;
  cin >> q;
  for(int i = 0;i < q;i++){
    ll l;
    ll r;
    cin >> l >> r;
    l--;
    cout << seg.query(l,r).components << endl;
  }
  return 0;
}
int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}