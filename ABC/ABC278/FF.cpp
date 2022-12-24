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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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
      T nxt = type ? Monoid::op(seg[2 * a + type],M) : Monoid::op(seg[2 * a + type],M);
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

struct monoid_min
{
  using T = ll;
  static T op(T l, T r) { return min(l,r); }
  static const T id() {
    return INT_MAX;
  }

  static const bool check(T &current, T &x) {
    return current <= x;
  }
};

struct monoid_max
{
  using T = ll;
  static T op(T l, T r) { return max(l,r); }
  static const T id() {
    return INT_MIN;
  }

  static const bool check(T &current, T &x) {
    return current >= x;
  }
};

struct monoid_sum
{
  using T = ll;
  static T op(T l, T r) { return l+r; }
  static const T id() {
    return 0;
  }

  static const bool check(T &current, T &x) {
    return current >= x;
  }
};

struct monoid_min_with_index
{
  using T = pair<ll,ll>;
  static T op(T &l, T &r) {
    if (l < r){
      return l;
    }else{
      return r;
    }
  }
  static const T id(){
    return {numeric_limits<ll>::max(),-1};
  }

  static const bool check(T &current, T &x) {
      return current < x;
  }
};

struct monoid_max_with_index
{
  using T = pair<ll,ll>;
  static T op(T &l, T &r) {
    if (l.first > r.first){
      return l;
    }else{
      return r;
    }
  }
  static const T id(){
    return {numeric_limits<ll>::min(),-1};
  }
};


template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2DCompressed {

  using merge_f = function< get_t(get_t, get_t) >;
  using range_get_f = function< get_t(structure_t &, int, int) >;
  using update_f = function< void(structure_t &, int, update_t) >;

  int sz;
  vector< structure_t > seg;
  const merge_f f;
  const range_get_f g;
  const update_f h;
  const get_t identity;
  vector< vector< int > > LL, RR;
  vector< vector< int > > beet;

  SegmentTree2DCompressed(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
      : f(f), g(g), h(h), identity(identity) {
    sz = 1;
    while(sz < n) sz <<= 1;
    beet.resize(2 * sz);
    LL.resize(2 * sz);
    RR.resize(2 * sz);
  }

  get_t update(int a, int x, int y, update_t z, int k, int l, int r) {
    if(r <= a || a + 1 <= l) return query(l,r,x,y,k,l,r);
    if(a <= l && r <= a + 1) {
        h(seg[k], x, z);
        return z;
    }
    get_t left = update(a, LL[k][x],LL[k][y], z, 2 * k + 0, l, (l + r) >> 1);
    get_t right = update(a, RR[k][x],RR[k][y], z, 2 * k + 1, (l + r) >> 1, r);
    get_t current = f(left,right);
    h(seg[k], x, current);
    return current;
  }


  void update(int x, int y, update_t z) {
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    update(x, y,y+1, z, 1, 0, sz);
  }

  get_t query(int a, int b, int x, int y, int k, int l, int r) {
    if(a >= r || b <= l) return identity;
    if(a <= l && r <= b) return g(seg[k], x, y);
    return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
             query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
  }

  get_t query(int a, int b, int x, int y) {
    x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return query(a, b, x, y, 1, 0, sz);
  }

  void build() {
    for(int k = (int) beet.size() - 1; k >= sz; k--) {
      sort(begin(beet[k]), end(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
    }
    for(int k = sz - 1; k > 0; k--) {
      beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
      merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
      LL[k].resize(beet[k].size() + 1);
      RR[k].resize(beet[k].size() + 1);
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < beet[k].size(); i++) {
        while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
        while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
        LL[k][i] = tail1, RR[k][i] = tail2;
      }
      LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
      RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
    }
    for(int k = 0; k < beet.size(); k++) {
      seg.emplace_back(structure_t(beet[k].size()));
    }
  }

  void preupdate(int x, int y) {
    beet[x + sz].push_back(y);
  }
};

int main()
{
  int H,W,N,h,w;
  cin >> H >> W >> N >> h >> w;
  vector<int> total(N);
  vector<vector<ll>> A(H,vector<ll>(W));
  auto ff = [](int x, int y) { return x+y; };
  auto gg = [](SegmentTree<monoid_sum> &k, int x, int y) { return k.query(x,y); };
  auto hh = [](SegmentTree<monoid_sum> &k, int x, int y) { k.update(x,y); };

  vector<SegmentTree2DCompressed< SegmentTree<monoid_sum>, int, int >> segs(N,SegmentTree2DCompressed<SegmentTree<monoid_sum>, int, int >(H,ff,gg,hh,0));
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      ll a;
      cin >> a;
      a--;
      total[a]++;
      A[i][j] = a;
      segs[a].preupdate(i,j);
    }
  }
  for(int i = 0;i < N;i++){
    // for(int j = 0;j < H;j++){
    //     for(int k = 0;k < W;k++){
    //         segs[i].preupdate(j,k);
    //     }
    // }
    segs[i].build();
  }
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      segs[A[i][j]].update(i,j,1);
    }
  }
  for(int i = 0;i+h <= H ;i++){
    for(int j = 0;j+w <= W;j++){
      ll ans = 0;
      for(int k = 0;k < N;k++){
        if (total[k] - segs[k].query(i,i+h,j,j+w) > 0){
          ans++;
        }
      }
      if (j != 0){
        cout << " ";
      }
      cout << ans;
    }
    cout << "\n";
  }
  cout << flush;
  return 0;
}