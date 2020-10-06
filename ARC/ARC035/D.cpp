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
namespace mp = boost::multiprecision;

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

struct monoid_map
{
  using T = double;
  static T op(T &l, T &r) {
    return l+ r;
  }
  static const T id() {
    return 0;
  }
};

map<long long,long long> decomposite(long long N, map<long long,long long> & primes,long long next_p = 2){
    if (N == 1){
        return primes;
    }


    while (next_p * next_p <= N ) {
        if (N % next_p == 0) {
            primes[next_p] += 1;
            return decomposite(N/next_p,primes,next_p);
        } else {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}
double combination(ll n,ll m, vector<double> &factorial_logs){
  return factorial_logs[n]- factorial_logs[m] - factorial_logs[n- m];
}
int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  SegmentTree<monoid_map> seg(N-1);
  vector<double> factorial_logs;
  factorial_logs.push_back(0);
  for(int i = 1;i <= 2000000;i++){
    factorial_logs.push_back(factorial_logs.back() + log(i));
  }
  vector<pair<ll,ll>> points(N);
  for(int i = 0;i < N;i++){
    scanf("%lld%lld", &points[i].first, &points[i].second);
  }
  for(int i = 0;i < N-1;i++){
    ll x = points[i+1].first - points[i].first;
    ll y = points[i+1].second - points[i].second;
    seg.set(i, combination(x+y,x,factorial_logs) );
  }
  seg.build();
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll type;
    scanf("%lld",&type);
    if(type == 1){
      ll k,a,b;
      scanf("%lld%lld%lld", &k, &a, &b);
      k--;
      points[k] = {a,b};
      if (k != 0){
        ll x = points[k].first - points[k-1].first;
        ll y = points[k].second - points[k-1].second;
        seg.update(k-1,combination(x+y,x,factorial_logs));
      }
      if(k < N - 1){
        ll x = points[k+1].first - points[k].first;
        ll y = points[k+1].second - points[k].second;
        seg.update(k,combination(x+y,x,factorial_logs));
      }
    }else{
      ll l1,r1,l2,r2;
      scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
      l1--;
      r1--;
      l2--;
      r2--;
      double value1 = seg.query(l1,r1);
      double value2 = seg.query(l2,r2);
      if (value1 > value2){
        cout << "FIRST" << "\n";
      }else{
        cout << "SECOND" << "\n";
      }
    }
  }
  cout << flush;

  return 0;
}