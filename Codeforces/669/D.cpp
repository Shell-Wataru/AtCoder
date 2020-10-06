#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;


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


int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> H(n);
  vector<ll> DP(n,numeric_limits<ll>::max());
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&H[i]);
  }
  DP[0] = 0;
  SegmentTree<monoid_max> seg_max(n);
  SegmentTree<monoid_min> seg_min(n);
  for(int i = 0;i < n;i++){
    seg_max.set(i,H[i]);
    seg_min.set(i,H[i]);
  }
  seg_max.build();
  seg_min.build();
  for(int i = 1;i < n;i++){
    DP[i] = min(DP[i],DP[i-1]+1);
    if (H[i] > H[i-1]){
      ll discrete_path = seg_max.find_last(i,H[i]);
      // cout << i << " " << discrete_path << endl;
      if (discrete_path != -1){
        DP[i] = min(DP[i],DP[discrete_path]+1);
      }
    }else if(H[i] < H[i-1]){
      ll discrete_path = seg_min.find_last(i,H[i]);
      // cout << i << " " << discrete_path << endl;
      if (discrete_path != -1){
        DP[i] = min(DP[i],DP[discrete_path]+1);
      }
    }
  }
  cout << DP[n-1] << endl;
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
  // cout << flush;
  return 0;
}