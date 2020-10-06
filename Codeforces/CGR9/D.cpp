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

struct monoid_mex
{
  using T = pair<ll,ll>;
  static T op(T l, T r) {
    return {l.first + r.first,l.second + r.second};
  }
  static const T id() {
    return {0,0};
  }

  static const bool check(T &current, T &x) {
    return current.first < current.second;
  }
};

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> A(n);
  vector<ll> counts(n+1,0);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&A[i]);
    counts[A[i]]++;
  }
  SegmentTree<monoid_mex> seg(n+1);
  for(int i = 0;i <= n;i++){
    if (counts[i] > 0){
      seg.set(i,{1,1});
    }else{
      seg.set(i,{0,1});
    }
  }
  seg.build();
  cout << 2*n << "\n";
  for(int i = 0;i < 2*n;i++){
    if (i != 0){
      cout << " ";
    }
    ll mex = seg.find_first(0,{0,0});
    // cout << "m" << mex << endl;
    // cout << "n" << n_index << endl;
    if (mex == n){
      ll n_index = n - 1;
      for(int j = 0;j < n;j++){
        if (A[j] != j){
          n_index = j;
        }
      }
      cout << n_index + 1;
      ll old = A[n_index];
      counts[mex]++;
      counts[old]--;
      A[n_index] = mex;
      seg.update(mex,{1,1});
      if (counts[old] == 0){
        seg.update(old,{0,1});
      }
      n_index++;
    }else{
      cout << mex + 1;
      ll old = A[mex];
      counts[mex]++;
      counts[old]--;
      A[mex] = mex;
      seg.update(mex,{1,1});
      if (counts[old] == 0){
        seg.update(old,{0,1});
      }
    }
  }
  cout << endl;
  // for(auto a:A){
  //   cout << a;
  // }
  // cout << endl;
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  // cout << flush;
  return 0;
}