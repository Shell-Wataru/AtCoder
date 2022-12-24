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
#include <unordered_set>
#include <climits>
using namespace std;
using ll = long long;

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      propagate(a);
      Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
      return -1;
    }
    thrust(a + sz);
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, reflect(a));
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
      if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
      return -1;
    }
    thrust(b + sz - 1);
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(reflect(--b), R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct monoid_sum
{
  ll value,size;
  bool operator==(const monoid_sum& x) { return x.value == value && x.size == size; }
  bool operator!=(const monoid_sum& x) { return !(x.value == value && x.size == size); }
};

struct operator_monoid_sum
{
  ll value;
  bool applied;
  bool operator==(const operator_monoid_sum& x) { return x.value == value && x.applied == applied; }
  bool operator!=(const operator_monoid_sum& x) { return !(x.value == value && x.applied == applied); }
};

monoid_sum f(monoid_sum a,monoid_sum b){
  return monoid_sum{a.value+b.value,a.size+b.size};
}
monoid_sum g(monoid_sum a,operator_monoid_sum b){
    if (b.applied){
        return a;
    }else{
        return monoid_sum{b.value*a.size,a.size};
    }

}
operator_monoid_sum h(operator_monoid_sum a,operator_monoid_sum b){
    if (b.applied){
        return a;
    }else{
        return b;
    }
}

int solve()
{
    ll N,Q,X;
    cin >> N >>Q >> X;
    vector<ll> A(N);
    LazySegmentTree<monoid_sum,operator_monoid_sum> lst(N,f,g,h,monoid_sum{0,0},operator_monoid_sum{0,true});
    ll ans = -1;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        if (a > X){
            lst.set(i,{1,1});
        }else if (a == X){
            ans = i;
            lst.set(i,{0,1});
        }else{
            lst.set(i,{0,1});
        }
    }
    lst.build();
    for(int i = 0;i < Q;i++){
        ll c,l,r;
        cin >> c >> l >> r;
        l--;
        if (c == 1){
            ll greater_count = lst.query(l,r).value;
            // cout << greater_count << endl;
            lst.update(l,r-greater_count,{0});
            lst.update(r-greater_count,r,{1});
            if (l <= ans && ans < r){
                ans = r-greater_count-1;
            }
        }else{
            ll greater_count = lst.query(l,r).value;
            lst.update(l,l+greater_count,{1});
            lst.update(l+greater_count,r,{0});
            if (l <= ans && ans < r){
                ans = l+greater_count;
            }
        }
        // for(int j = 0;j < N;j++){
        //     cout << lst[j].value << ",";
        // }
        // cout << endl;
    }
    // for(int i = 0;i < N;i++){
    //     cout << lst[i].value << ",";
    // }
    // cout << endl;
    cout << ans + 1<< endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
