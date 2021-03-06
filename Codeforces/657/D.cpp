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

struct ll_with_next
{
  ll value, l, i, r;
};
struct monoid_min
{
  using T = ll_with_next;
  static T op(T &l, T &r)
  {
    if (l.value < r.value)
    {
      return l;
    }
    else
    {
      return r;
    }
  }
  static const T id()
  {
    return {numeric_limits<ll>::max(), -1, -1, -1};
  }

  static const bool check(T &current, T &x)
  {
    return true;
  }
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> A(n);
  for (ll i = 0; i < n; i++)
  {
    scanf("%lld", &A[i]);
  }
  vector<ll> B(n);
  for (ll i = 0; i < n; i++)
  {
    B[i] = A[2*i %n];
  }
  ll total = 0;
  for (auto a : B)
  {
    // cout << a << ",";
    total += a;
  }
  // cout << endl;
  ll choose = 0;
  for (int i = 0; i < n / 2; i++)
  {
    choose += B[i];
  }
  // cout << choose << endl;
  ll min_choose = choose;
  for (int i = 0; i < n; i++)
  {
    choose -= B[i];
    choose += B[(i + n / 2) % n];
    min_choose = min(min_choose, choose);
  }
  // cout << min_choose << endl;
  cout << total - min_choose << endl;
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}