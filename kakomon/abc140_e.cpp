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

  // 条件を満たす[a,b)で最もbが前方にあるもの
  int find_first(int a, T x) {
    T L = id;
    if(a <= 0) {
      if(Monoid::check(seg[1],x)) return find_subtree(1, x, L, false) + 1;
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        T nxt = Monoid::op(L, seg[a]);
        if(Monoid::check(seg[a],x)) return find_subtree(a, x, L, false) + 1;
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

struct monoid_max
{
  using T = ll;
  static T op(T l, T r) { return max(l,r); }
  static const T id() {
    return INT_MIN;
  }

  static const bool check(T &current, T &x) {
    return current > x;
  }
};

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> P(N);
    SegmentTree<monoid_max> seg(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        seg.set(i,P[i]);
    }
    seg.build();
    ll ans = 0;
    for(int i = 0; i < N;i++){
        ll l1,l2,r1,r2;
        l1 = seg.find_last(i,P[i]);
        r1 = seg.find_first(i,P[i]);
        if (r1 != -1){
            r1--;
        }
        if (l1 != -1){
            l2 = seg.find_last(l1,P[i]);
        }
        if (r1 != -1){
            r2 = seg.find_first(r1+1,P[i]);
            if (r2 != -1){
                r2--;
            }
        }
        ll il1_range,l1l2_range,ir1_range,r1r2_range;
        if (l1 != -1){
            il1_range = i - l1;
        }else{
            il1_range = i + 1;
        }
        if (r1 != -1){
            ir1_range = r1 - i;
        }else{
            ir1_range = N - i;
        }

        if (l1 == -1){
            l1l2_range = 0;
        }else if (l2 == -1){
            l1l2_range = l1 + 1;
        }else{
            l1l2_range = l1 - l2;
        }

        if (r1 == -1){
            r1r2_range = 0;
        }else if (r2 == -1){
            r1r2_range = N - r1;
        }else{
            r1r2_range = r2 - r1;
        }
        // cout << P[i] << endl;
        // cout << "l1:" << l1 << endl;
        // cout << "l2:" << l2 << endl;
        // cout << "r1:" << r1 << endl;
        // cout << "r2:" << r2 << endl;

        // cout << "il1_range:" << il1_range << endl;
        // cout << "ir1_range:" << ir1_range << endl;
        // cout << "l1l2_range:" << l1l2_range << endl;
        // cout << "r1r2_range:" << r1r2_range << endl;
        ll range = il1_range * r1r2_range + ir1_range * l1l2_range;
        ans += P[i] *  range;
    }
    cout << ans << endl;
    return 0;
}