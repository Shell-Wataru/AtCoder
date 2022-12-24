#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
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

struct monoid
{
  using T = pair<string,ll>;
  static T op(T l, T r) {
    string merged = l.first+r.first;
    // cout << merged << "->";
    ll count = l.second + r.second;
    bool changed = true;
    ll index = 0;
    while(index + 1 < merged.size()){
        if (merged[index] == merged[index+1]){
            // cout << "!";
            merged.erase(index+1,1);
        }else{
            index++;
        }
    }
    index = 0;
    while(index + 2 < merged.size()){
        if (merged[index] == merged[index+2]){
            // cout << "?";
            merged.erase(index+1,2);
            count++;
        }else{
            index++;
        }
    }
    while(merged.size()>= 5){
        // cout << "+";
        count++;
        merged.erase(3,1);
        merged.erase(1,1);
    }
    // cout << merged << endl;
    return {merged,count};
    }
  static const T id() {
    return {"",0};
  }

  static const bool check(T &current, T &x) {
    return current <= x;
  }
};


int solve()
{
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    SegmentTree<monoid> seg(N);
    for(int i = 0;i < N;i++){
        seg.set(i,{S.substr(i,1),0});
    }
    seg.build();
    for(int i = 0;i < Q;i++){
        ll l,r;
        cin >> l >> r;
        l--;
        auto d = seg.query(l,r);
        // cout << d.first << " " << d.second << endl;
        if (d.first.size() <= 1){
            cout << d.second << "\n";
        }else if (d.first.size() == 2){
            cout << d.second + 1<< "\n";
        }else{
            cout << d.second + 2<< "\n";
        }
    }
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // while(t--){
    solve();
    // }
    return 0;
}