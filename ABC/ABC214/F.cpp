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
#include <set>
#include <climits>
using namespace std;
using ll = long long;

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
// 全体が1
template <typename Monoid>
struct SegmentTree
{
  using T = typename Monoid::T;

  int sz;
  vector<T> seg;
  const T id = Monoid::id();

  SegmentTree(int n)
  {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, id);
  }

  void set(int k, const T &x)
  {
    seg[k + sz] = x;
  }

  void build()
  {
    for (int k = sz - 1; k > 0; k--)
    {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const T &x)
  {
    k += sz;
    seg[k] = x;
    while (k >>= 1)
    {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T query(int a, int b)
  {
    T L = id, R = id;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        L = Monoid::op(L, seg[a++]);
      if (b & 1)
        R = Monoid::op(seg[--b], R);
    }
    return Monoid::op(L, R);
  }

  T operator[](const int &k) const
  {
    return seg[k + sz];
  }

  int find_subtree(int a, T &x, T &M, bool type)
  {
    while (a < sz)
    {
      T nxt = type ? seg[2 * a + type] : seg[2 * a + type];
      if (Monoid::check(nxt, x))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  // 条件を満たす[a,b]で最もbが前方にあるもの
  int find_first(int a, T x)
  {
    T L = id;
    if (a <= 0)
    {
      if (Monoid::check(seg[1], x))
        return find_subtree(1, x, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
      {
        T nxt = Monoid::op(L, seg[a]);
        if (Monoid::check(seg[a], x))
          return find_subtree(a, x, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  // 条件を満たす[a,b)で最もaが後方にあるもの
  int find_last(int b, T x)
  {
    T R = id;
    if (b >= sz)
    {
      if (Monoid::check(seg[1], x))
        return find_subtree(1, x, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (b & 1)
      {
        T nxt = Monoid::op(seg[--b], R);
        if (Monoid::check(nxt, x))
          return find_subtree(b, x, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct monoid_min
{
  using T = ll;
  static T op(T l, T r) { return min(l, r); }
  static const T id()
  {
    return INT_MAX;
  }

  static const bool check(T &current, T &x)
  {
    return current <= x;
  }
};

struct monoid_max
{
  using T = ll;
  static T op(T l, T r) { return max(l, r); }
  static const T id()
  {
    return INT_MIN;
  }

  static const bool check(T &current, T &x)
  {
    return current >= x;
  }
};

ll farthest_distance(ll current, vector<ll> &xs, SegmentTree<monoid_max> &seg_max, SegmentTree<monoid_min> &seg_min, ll l, ll r)
{
  if (l + 1 == r)
  {
    return l;
  }
  ll N = xs.size();
  ll center = (l + r) / 2;
  ll current_x = xs[current];
  ll current_y = seg_min[current];
  ll greater_x = lower_bound(xs.begin(), xs.end(), current_x + center) - xs.begin();
  ll lower_x = upper_bound(xs.begin(), xs.end(), current_x - center) - xs.begin();
  if (seg_max.query(0, lower_x) >= current_y + center ||
      seg_max.query(greater_x, N) >= current_y + center ||
      seg_min.query(0, lower_x) <= current_y - center ||
      seg_min.query(greater_x, N) <= current_y - center)
  {
    return farthest_distance(current, xs, seg_max, seg_min, center, r);
  }
  else
  {
    return farthest_distance(current, xs, seg_max, seg_min, l, center);
  }
}

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll, ll>> points(N);
  for (int i = 0; i < N; i++)
  {
    ll x, y;
    cin >> x >> y;
    points[i].first = x;
    points[i].second = y;
  }
  sort(points.begin(), points.end());
  SegmentTree<monoid_max> seg_max(N);
  SegmentTree<monoid_min> seg_min(N);
  vector<ll> xs(N);
  for (int i = 0; i < N; i++)
  {
    xs[i] = points[i].first;
    seg_max.set(i, points[i].second);
    seg_min.set(i, points[i].second);
  }
  seg_max.build();
  seg_min.build();
  ll ans = 0;
  for(int i = 0;i < N;i++){
    ans = max(ans,farthest_distance(i,xs,seg_max,seg_min,0,numeric_limits<ll>::max()));
  }
  cout << ans << endl;
  return 0;
}