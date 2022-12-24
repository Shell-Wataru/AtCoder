#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
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
    return {numeric_limits<ll>::max(),-1};
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
    return {numeric_limits<ll>::min(),-1};
  }
};

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  vector<ll> b(n);

  SegmentTree<monoid_min> seg(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    seg.set(i,a[i]-i-1);
    // cout << a[i]- i -1 << ",";
  }
  seg.build();
  ll ans = 0;
  vector<ll> rs1(n);
  vector<ll> rs2(n);
  vector<ll> updated_rs(n);
  vector<ll> cum_sum1(n+1,0);
  vector<ll> cum_sum2(n+1,0);
  for(int i = 0;i < n;i++){
    ll r1 = seg.find_first(i,-i-1);
    // cout << r1 << ",";
    ll r2;
    if (r1 == -1 || r1 == n-1) {
      r2 = -1;
    }else{
      r2 = seg.find_first(r1+1,-i-1);
    }
    if (r1 == -1){
      ans += n - i;
      cum_sum1[i+1] = cum_sum1[i] + n-i;
      rs1[i] = n;
    }else{
      ans += r1-i;
      rs1[i] = r1;
      cum_sum1[i+1] = cum_sum1[i] + r1-i;
    }
    if (r2 == -1){
      cum_sum2[i+1] = cum_sum2[i] + n-i;
      rs2[i] = n;
    }else{
      rs2[i] = r2;
      cum_sum2[i+1] = cum_sum2[i] + r2-i;
    }
  }
  // cout << endl;
  // cout << "default" << ans << "\n";
  ll q;
  cin >> q;
  for(int i = 0;i < q;i++){
    ll p,x;
    scanf("%lld",&p);
    scanf("%lld",&x);
    p--;
    if (x > a[p]){
      ll index1 = lower_bound(rs1.begin(),rs1.end(),p) - rs1.begin();
      ll index2 = lower_bound(rs1.begin(),rs1.end(),p+1) - rs1.begin();
      // cout << "A" << endl;
      if (index1 == index2){
        cout << ans << "\n";
      }else{
        ll updates_from_index = max(p-(x-1),index1);
        ll updates_to_index = min(index2,p+1);
        if (updates_to_index - updates_from_index >= 0){
          cout << cum_sum1[updates_from_index] + (cum_sum2[updates_to_index] - cum_sum2[updates_from_index]) + (cum_sum1[n] - cum_sum1[updates_to_index]) << "\n";
        }else{
          cout << cum_sum1[n] << "\n";
        }

      }
    }else if (x == a[p]){
      // cout << "B" << endl;
      cout << ans << "\n";
    }else{
      // cout << "C" << endl;
      ll index1 = lower_bound(rs1.begin(),rs1.end(),p+1) - rs1.begin();
      ll index2 = p-x+1;
      // cout << index1  << "~" << index2<< endl;
      ll d = max(index2-index1,0ll);
      // cout << "d" << d << endl;
      // cout << "p"  << p<< endl;
      if (d >= 0){
        cout << cum_sum1[index1] + (p-index1 + p-(index2-1))*d/2 + (cum_sum1[n] - cum_sum1[index2]) << "\n";
      }else{
        cout << cum_sum1[n] << "\n";
      }

    }
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
