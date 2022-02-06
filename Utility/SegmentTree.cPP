#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <climits>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
double MAX_VALUE = 1000001;

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
    return {INT_MAX,-1};
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
    return {INT_MIN,-1};
  }
};

int main() {
  // vector<int> a{1,2,3,4,5,6,7,8};
  vector<int> a{8,7,6,5,4,3,2,1};
  SegmentTree< monoid_min > seg(a.size());
  for(int i = 0;i < a.size();i++){
      seg.set(i, a[i]);
  }
  seg.build();
  // cout << seg.query(0,a.size()) << endl;
  // seg.update(0,10);
  // cout << seg.query(0,a.size()) << endl;
  // seg.update(0,1);
  // cout << seg.find_first(0,4) << endl;
  // cout << seg.find_first(1,4) << endl;
  cout << seg.find_last(0,9) << endl;
  cout << seg.find_last(0,8) << endl;
  cout << seg.find_last(0,7) << endl;
  // cout << seg.find_last(a.size(),4) << endl;
  // cout << seg.find_last(a.size()-1,4) << endl;
}