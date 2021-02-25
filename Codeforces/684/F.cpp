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


// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
// 全体が1
template< typename Monoid >
struct SegmentTree {
  using T = typename Monoid::T;

  int sz;
  int depth;
  vector< T > seg;
  vector<bool> swaps;
  vector<bool> reverses;
  const T id = Monoid::id();

  SegmentTree(int n) {
    sz = 1;
    depth = 1;
    while(sz < n) {
        sz <<= 1;
        depth++;
    }
    seg.assign(2 * sz, id);
    swaps.assign(depth,false)
    reverses.assign(depth,false)
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
    for(int i = 0;i < depth;i++){
        ll base_size = 1<<(depth - i);
        if (swaps[i] && reverses[i]){

        }else if (swaps[i] && !reverses[i]){
        }else if (!swaps[i] && reverses[i]){
            k = 1<<(depth - i)
        }else if (!swaps[i] && !reverses[i]){
            continue
        }
    }
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


int solve()
{

    ll N;
    cin >> N;
    vector<pair<ll,ll>> A(N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%lld",&A[i].first);
        scanf("%lld",&A[i].second);
    }
    ll count = 0;
    sort(A.begin(),A.end(),[](pair<ll,ll> &l,pair<ll,ll> &r ){
        if (l.first == r.first){
            return l.second > r.second;
        }else{
            return l.first < r.first;
        }
    });
    vector<pair<ll,ll>> s;
    for(int i = 0;i < N;i++){
        while(!s.empty() && s.back().second < A[i].first){
            s.pop_back();
        }
        if (s.empty() || A[i].second <= s.back().second){
            // cout << A[i].first << "~" <<A[i].second << endl;
            count++;
            s.push_back(A[i]);
        }
    }
    cout << count << endl;
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
    return 0;
}