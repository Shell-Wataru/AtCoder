#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
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

int find_remove_plus(ll begin, ll end,ll l,ll r, SegmentTree<monoid_sum> &seg){
  if (l+1 == r){
    ll first = seg.query(begin,l);
    ll second = seg.query(l+1,end);
    // cout << "r:" << first - second << endl;
    return l;
  }
  ll center = (l+r)/2;
  ll first = seg.query(begin,center);
  ll second = seg.query(center+1,end);
  // cout << l << "~" << r << ":" << first - second << endl;
  if (first - second <= 0){
    return find_remove_plus(begin,end,center,r,seg);
  }else{
    return find_remove_plus(begin,end,l,center,seg);
  }
}

int find_remove_minus(ll begin, ll end,ll l,ll r, SegmentTree<monoid_sum> &seg){
  if (l+1 == r){
    ll first = seg.query(begin,l);
    ll second = seg.query(l+1,end);
    // cout << "r:" << first - second << endl;
    return l;
  }
  ll center = (l+r)/2;
  ll first = seg.query(begin,center);
  ll second = seg.query(center+1,end);
  // cout << l << "~" << r <<  " c" << center << ":" << first - second << endl;
  if (first - second >= 0){
    return find_remove_minus(begin,end,center,r,seg);
  }else{
    return find_remove_minus(begin,end,l,center,seg);
  }
}

int solve()
{
  ll n, q;
  scanf("%lld", &n);
  scanf("%lld", &q);
  SegmentTree<monoid_sum> seg(n);
  string s;
  cin >> s;
  for(int i = 0;i < n;i++){
    if ( (s[i] == '+') ^ (i % 2 == 0) ){
      seg.set(i,1);
    }else{
      seg.set(i,-1);
    }
  }
  seg.build();
  for(int i = 0;i < q;i++){
    ll l,r;
    scanf("%lld",&l);
    scanf("%lld",&r);
    l--;
    ll diff = abs(seg.query(l,r));
    if (diff == 0){
      cout << 0 << "\n";
    }else if(diff % 2 == 1){
      ll start = seg.query(0,l);
      ll end = seg.query(0,r);
      cout << 1 << "\n";
      if (end - start > 0){
        cout << find_remove_plus(l,r,l,r,seg) + 1 << "\n";
      }else{
        cout << find_remove_minus(l,r,l,r,seg) + 1 << "\n";
      }
    }else{
      ll start = seg.query(0,l+1);
      ll end = seg.query(0,r);
      cout << 2 << "\n";
      if (end - start > 0){
        cout << l + 1<< " " <<  find_remove_plus(l+1,r,l+1,r,seg) + 1 << "\n";
      }else{
        cout << l + 1<< " " <<  find_remove_minus(l+1,r,l+1,r,seg) + 1 << "\n";
      }
    }

  }
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}
