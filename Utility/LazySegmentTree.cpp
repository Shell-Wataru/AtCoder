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

struct operator_monoid_add
{
  ll value;
  bool operator==(const operator_monoid_add& x) { return x.value == value; }
  bool operator!=(const operator_monoid_add& x) { return x.value != value; }
};

monoid_sum f(monoid_sum a,monoid_sum b){
  return monoid_sum{a.value+b.value,a.size+b.size};
}
monoid_sum g(monoid_sum a,operator_monoid_add b){
  return monoid_sum{a.value+b.value*a.size,a.size};
}

operator_monoid_add h(operator_monoid_add a,operator_monoid_add b){
  return operator_monoid_add{a.value+b.value};
}


struct operator_monoid_update
{
  ll value;
  bool applied;
  bool operator==(const operator_monoid_update& x) { return x.value == value && x.applied == applied; }
  bool operator!=(const operator_monoid_update& x) { return !(x.value == value && x.applied == applied); }
};

// monoid_sum f(monoid_sum a,monoid_sum b){
//   return monoid_sum{a.value+b.value,a.size+b.size};
// }
// monoid_sum g(monoid_sum a,operator_monoid_update b){
//     if (b.applied){
//         return a;
//     }else{
//         return monoid_sum{b.value*a.size,a.size};
//     }

// }
// operator_monoid_update h(operator_monoid_update a,operator_monoid_update b){
//     if (b.applied){
//         return a;
//     }else{
//         return b;
//     }
// }


int add(int a,int b){
  return a+b;
}
int main(){
  vector<int> a{1,2,3,4,5,6,7,8};
  LazySegmentTree<monoid_sum,operator_monoid_add> lst(a.size(),f,g,h,monoid_sum{0,0},operator_monoid_add{0});
  for(int i = 0;i < a.size();i++){
    lst.set(i,{a[i],1});
  }
  lst.build();
  cout << lst.query(0,4).value << endl;
  lst.update(0,4,{10});
  cout << lst.query(0,4).value << endl;
}