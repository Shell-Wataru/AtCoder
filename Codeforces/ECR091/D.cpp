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

struct monoid_max
{
  using T = ll;
  static T op(T l, T r) { return max(l, r); }
  static const T id()
  {
    return numeric_limits<ll>::min();
  }

  static const bool check(T &current, T &x)
  {
    return current <= x;
  }
};

int solve()
{
  int n;
  scanf("%d", &n);
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld", &A[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      ans += A[i];
    }
  }
  vector<ll> even_reverses;
  even_reverses.push_back(0);
  for (size_t i = 0; 2 * i + 1 < n; i++)
  {
    even_reverses.push_back(A[2 * i + 1] - A[2 * i]);
  }
  for (int i = 1; i < even_reverses.size(); i++)
  {
    even_reverses[i] += even_reverses[i - 1];
  }
  vector<ll> odd_reverses;
  odd_reverses.push_back(0);
  for (size_t i = 0; 2 * i + 2 < n; i++)
  {
    odd_reverses.push_back(A[2 * i + 1] - A[2 * i + 2]);
  }
  for (int i = 1; i < odd_reverses.size(); i++)
  {
    odd_reverses[i] += odd_reverses[i - 1];
  }
  SegmentTree<monoid_max> odd_seg(odd_reverses.size());
  SegmentTree<monoid_max> even_seg(even_reverses.size());
  for (int i = 0; i < even_reverses.size(); i++)
  {
    even_seg.set(i, even_reverses[i]);
  }
  even_seg.build();
  for (int i = 0; i < odd_reverses.size(); i++)
  {
    odd_seg.set(i, odd_reverses[i]);
  }
  odd_seg.build();

  ll max_even = numeric_limits<ll>::min();
  ll max_odd = numeric_limits<ll>::min();
  for (int i = 0; i < even_reverses.size(); i++)
  {
    max_even = max(max_even, even_seg.query(i, even_reverses.size()) - even_reverses[i]);
  }
  for (int i = 0; i < odd_reverses.size(); i++)
  {
    max_odd = max(max_odd, odd_seg.query(i, odd_reverses.size()) - odd_reverses[i]);
  }
  // cout << max_odd << "," << max_even << endl;
  // cout << even_reverses.size() << "," << odd_reverses.size() << endl;
  cout << max(ans + max_odd, ans + max_even) << endl;
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