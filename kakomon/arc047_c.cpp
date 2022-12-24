#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
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

    int find_subtree(int a, T &x, T &M, bool type) {
    while(a < sz) {
      T nxt = type ? Monoid::op(seg[2 * a + type],M) : Monoid::op(seg[2 * a + type],M);
      if(Monoid::check(nxt,x)) a = 2 * a + type;
      else M = nxt,a = 2 * a + 1 - type;
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

struct monoid_sum
{
    using T = ll;
    static T op(T l, T r) { return l + r; }
    static const T id()
    {
        return 0;
    }

    static const bool check(T &current, T &x)
    {
        return current >= x;
    }
};

struct monoid_min_with_index
{
    using T = pair<ll, ll>;
    static T op(T &l, T &r)
    {
        if (l < r)
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
        return {INT_MAX, -1};
    }

    static const bool check(T &current, T &x)
    {
        return current < x;
    }
};

struct monoid_max_with_index
{
    using T = pair<ll, ll>;
    static T op(T &l, T &r)
    {
        if (l.first > r.first)
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
        return {INT_MIN, -1};
    }
};

int solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        for (int i = n; i >= 1; i--)
        {
            cout << i << "\n";
        }
        return 0;
    }
    else if (k == n)
    {
        vector<ll> ans(n);
        iota(ans.begin(), ans.end(), 1);
        reverse(ans.begin() + 1, ans.end());
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << "\n";
        }
        return 0;
    }
    vector<ll> a(n + 1);
    vector<ll> factors(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        factors[i] = factors[i - 1] * i;
    }
    ll current = n;
    ll last_index;
    for (int i = n - 1; i >= 1; i--)
    {
        if (i > k)
        {
            a[i] = current / k;

            current = i * (current % k);
        }
        else if (i == k)
        {
            a[i] = current / k;
            current = (current % k);
        }
        else
        {
            a[i] = current;
            current = 0;
        }
        if (a[i] > 0)
        {
            last_index = i;
        }
    }
    // ll calc = 0;
    // for (int i = 1; i <= n - 1; i++)
    // {
    //     calc += a[i] * factors[i];
    //     cout << i << ":" << a[i] << endl;
    // }
    // cout << "ans:" << factors[n] / k << endl;
    // cout << "calc:" << calc << endl;
    SegmentTree<monoid_sum> seg(n);
    for (int i = 0; i < n; i++)
    {
        seg.set(i, 1);
    }
    seg.build();
    vector<ll> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (last_index == i)
        {
            ll index = seg.find_first(0, a[i]);
            // cout <<"index" << index << endl;
            ans.push_back(index);
            seg.update(index, 0);
            for (int j = n - 1; j >= 0; j--)
            {
                if (seg[j] == 1)
                {
                    ans.push_back(j);
                }
            }
            break;
        }
        else
        {
            ll index = seg.find_first(0, a[i] + 1);
            // cout <<"a[i]" << a[i] << endl;
            // cout <<"index" << index << endl;
            // for(int j = 0;j < n;j++){
            //     cout << seg.query(0,j+1);
            // }
            // cout << endl;
            ans.push_back(index);
            seg.update(index, 0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << "\n";
    }
    return 0;
}
int main()
{
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
