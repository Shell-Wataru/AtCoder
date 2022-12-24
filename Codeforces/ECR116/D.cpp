#include <iostream>
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

ll coloring(ll l,ll r, vector<pair<ll,ll>> &mM, vector<pair<ll,ll>> &Mm){

}

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<vector<ll>> a(n,vector<ll>(m));
  for(int i =0 ;i < n;i++){
    for(int j = 0;j < m;j++){
      scanf("%lld",&a[i][j]);
    }
  }
  vector<SegmentTree<monoid_max>> seg_maxs(n,SegmentTree<monoid_max>(m));
  vector<SegmentTree<monoid_min>> seg_mins(n,SegmentTree<monoid_min>(m));
  for(int i =0 ;i < n;i++){
    for(int j = 0;j < m;j++){
      seg_maxs[i].set(j,a[i][j]);
      seg_mins[i].set(j,a[i][j]);
    }
    seg_maxs[i].build();
    seg_mins[i].build();
  }
  for(int i = 1;i < m-1;i++){
    vector<vector<ll>> mM(n);
    vector<vector<ll>> Mm(n);
    for(int j = 0;j < n;j++){
      mM.push_back({seg_mins[j].query(0,i),seg_maxs[j].query(i,m)});
      Mm.push_back({seg_maxs[j].query(0,i),seg_mins[j].query(i,m)});
    }
  }
  cout << "No\n";
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
  cout << flush;
  return 0;
}