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
ll BASE_NUM = 998244353;


// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
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

  template< typename C >
  int find_subtree(int a, const C &check, T &M, bool type) {
    while(a < sz) {
      T nxt = type ? Monoid::op(seg[2 * a + type], M) : Monoid::op(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  int find_first(int a, const C &check) {
    T L = id;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        T nxt = Monoid::op(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    T R = id;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        T nxt = Monoid::op(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct monoid_min_with_index
{
  using T = pair<ll,ll>;
  static T op(T l, T r) {
    if (l.first < r.first){
      return l;
    }else{
      return r;
    }
  }
  static const T id(){
    return {INT_MAX,-1};
  }
};

int solve()
{
  ll n, k;
  scanf("%lld%lld", &n, &k);
  vector<ll> M(n);
  vector<ll> C(k);
  SegmentTree<monoid_min_with_index> seg(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &M[i]);
  }
  for (int i = 0; i < k; i++)
  {
    scanf("%lld", &C[i]);
  }
  sort(M.begin(), M.end(),greater<ll>());
  vector<vector<ll>> ans(1);
  for(int i = 0;i < n;i++){
    ll m = M[i];
    auto p = seg.query(0,n);
    if (p.first >=  C[m-1]){
      ans.push_back({m});
      seg.update(ans.size()-1,{1,ans.size()-1});
    }else{
      ans[p.second].push_back(m);
      seg.update(p.second,{p.first+1,p.second});
    }
  }
  cout << ans.size() << "\n";
  for(auto a:ans){
    cout << a.size();
    for(auto aa:a){
      cout << " " << aa;
    }
    cout << "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  return 0;
}