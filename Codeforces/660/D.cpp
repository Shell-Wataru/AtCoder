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
int BASE_NUM = 998244353;


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

struct node_data{
  ll from_counts,value,index;
};
struct monoid_min
{
  using T = node_data;
  static T &op(T &l, T &r) {
    if (l.from_counts != r.from_counts){
      if (l.from_counts < r.from_counts){
        return l;
      }else{
        return r;
      }
    }else if (l.value != r.value){
      if (l.value > r.value){
        return l;
      }else{
        return r;
      }
    }else{
      if (l.index < r.value){
        return l;
      }else{
        return r;
      }
    }
  }
  static const T id() {
    return {numeric_limits<ll>::max(),};
  }
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> A( n);
  vector<ll> B( n);
  vector<vector<ll>> G(n);

  for (ll i = 0; i <  n; i++)
  {
    scanf("%lld", &A[i]);
  }

  for (ll i = 0; i <  n; i++)
  {
    ll b;
    scanf("%lld", &b);
    b--;
    B[i] = b;
    if (b >= 0){
      G[b].push_back(i);
    }
  }
  SegmentTree<monoid_min> seg(n);
  for(ll i = 0; i < n;i++){
    seg.set(i,{(ll)G[i].size(),A[i],i});
  }
  seg.build();
  ll ans = 0;
  vector<ll> operations;
  while(seg.query(0,n).from_counts == 0){
    auto d= seg.query(0,n);
    ans += d.value;
    seg.update(d.index,{BASE_NUM,d.value,d.index});
    operations.push_back(d.index);
    if (d.value < 0){
      if (B[d.index] >= 0){
        auto next = seg[B[d.index]];
        seg.update(B[d.index],{next.from_counts - 1,next.value,next.index});
      }
    }else{
      if (B[d.index] >= 0){
        auto next = seg[B[d.index]];
        seg.update(B[d.index],{next.from_counts - 1,next.value + d.value,next.index});
      }
    }
  }
  cout << ans << endl;
  for (size_t i = 0; i < operations.size(); i++)
  {
    if (i != 0){
      cout << " ";
    }
    cout << operations[i] + 1;
  }
  cout << endl;
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