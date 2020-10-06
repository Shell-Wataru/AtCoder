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

struct monoid_max
{
  using T = pair<ll,ll>;
  static T op(T l, T r) {
      return max(l,r);
    }
  static const T id() {
    return {0,-1};
  }

//   static const bool check(T &current, T &x) {
//     return current <= x;
//   }
};

int solve()
{

    ll n,m;
    scanf("%lld",&n);
    scanf("%lld",&m);
    vector<set<ll>> G_FROM(n);
    vector<set<ll>> G_TO(n);
    for (size_t i = 0; i < m; i++)
    {
        ll a,b;
        scanf("%lld",&a);
        scanf("%lld",&b);
        a--;
        b--;
        G_TO[a].insert(b);
        G_FROM[b].insert(a);
    }
    SegmentTree<monoid_max> seg(n);
    for(int i = 0;i < n;i++){
        ll from = G_FROM[i].size();
        ll to = G_TO[i].size();
        seg.set(i,{min(from,to),i});
    }
    seg.build();
    vector<ll> removes;
    // vector<bool> actives(n,true);
    while(seg.query(0,n).first > 0){
        auto min_p = seg.query(0,n);
        ll index = min_p.second;
        // cout << index << min_p.second << endl;
        // actives[index] = false;
        seg.update(index,{0,index});
        for(auto from:G_FROM[index]){
            G_TO[from].erase(index);
            seg.update(from,{min(G_FROM[from].size(),G_TO[from].size()),from});
        }
        for(auto to:G_TO[index]){
            G_FROM[to].erase(index);
            seg.update(to,{min(G_FROM[to].size(),G_TO[to].size()),to});
        }

        G_TO[index].clear();
        G_FROM[index].clear();

        removes.push_back(index);
    }
    for(int i = 0;i < n;i++){
      cout << G_FROM[i].size() << " " << G_TO[i].size() << endl;
      cout << seg[i].first << endl;
    }
    cout << removes.size() << "\n";
    for(int i = 0;i< removes.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << removes[i] + 1;
    }
    cout << "\n";
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