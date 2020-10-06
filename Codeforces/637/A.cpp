#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

int solve()
{
    ll n;
    cin >> n;
    vector<ll> P(n);
    vector<ll> Indexes(n);
    for(int i = 0;i< n;i++){
        cin >> P[i];
        P[i]--;
    }
    for(int i = 0;i < n;i++){
        Indexes[P[i]] = i;
    }
    SegmentTree< int > seg_max(n, [](int a, int b) { return max(a, b); }, 0);
    SegmentTree< int > seg_next_right(n, [](int a, int b) {
        if (a == -1){
            return b;
        }else{
            return a;
        }
    }, -1);
    for(int i = 0;i< n;i++){
        seg_max.set(i,1);
        seg_next_right.set(i,i);
    }
    seg_max.build();
    seg_next_right.build();
    bool can_make = true;
    for(int i = 0;i < n;i++){
        // cout << "max:" << seg_max.query(0,n) << " i:" << seg_max.query(Indexes[i],Indexes[i]+1) << endl;
        if (seg_max.query(0,n) == seg_max.query(Indexes[i],Indexes[i]+1)){
            seg_max.update(Indexes[i],0);
            seg_next_right.update(Indexes[i],-1);
            ll next_r = seg_next_right.query(Indexes[i],n);;
            if (next_r != -1){
                // cout << "update" << endl;
                seg_max.update(next_r, seg_max.query(next_r,next_r + 1) + 1);
            }
        }else{
            can_make = false;
            break;
        }
    }
    if (can_make){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}