#include<iostream>
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

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    set<ll> not_fixed;
    string ans(N,'0');
    for(int i = 0;i < N;i++){
      not_fixed.insert(i);
    }
    vector<pair<ll,ll>> ranges(M);
    for(int i = 0;i < M;i++){
      ll l,r;
      cin >> l >> r;
      l--;
      ranges[i] = {l,r};
    }
    sort(ranges.begin(),ranges.end(),[](auto l, auto r){
      if (l.first == r.first){
        return l.second > r.second;
      }else{
        return l.first < r.first;
      }
    });
    SegmentTree<monoid_sum> seg(N);
    for(auto p:ranges){
      ll ones = (p.second - p.first)/2 - seg.query(p.first,p.second);
      cout << p.first << "~" << p.second << endl;
      cout << "add:"<<ones << endl;
      for(int i = 0;i < ones;i++){
        auto iter = not_fixed.lower_bound(p.second);
        iter--;
        cout << *iter << endl;
        ans[*iter] = '1';
        seg.update(*iter,1);
        not_fixed.erase(iter);
      }
      while(true){
        auto iter = not_fixed.lower_bound(p.first);
        if (iter == not_fixed.end() || *iter >= p.second){
          break;
        }else{
          not_fixed.erase(iter);
        }
      }
      cout << ans << endl;
    }
    // cout << not_fixed.size() << endl;
    cout << "check!!" << endl;
    string aaa = "00100100101101001011";
    for(auto p:ranges){
      if (seg.query(p.first,p.second) != (p.second - p.first) / 2){
          cout << p.first << "~" << p.second << endl;
      }

    }
    cout << ans << endl;
    return 0;
}