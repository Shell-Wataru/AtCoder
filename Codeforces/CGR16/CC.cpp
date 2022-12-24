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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

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

    // 条件を満たす[a,b)で最もbが前方にあるもの
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

struct monoid
{
    using T = vector<int>;
    static T op(T &l, T &r)
    {
        return {
            max(l[0]+ r[2],l[1] +r[0]),//pp
            max(l[0]+ r[3],l[1] +r[1]),//pn
            max(l[2]+ r[2],l[3] +r[0]),//np
            max(l[2]+ r[3],l[3] +r[1])//nn
        };
    }
    static const T id()
    {
        return {numeric_limits<int>::min()/2,0,0,numeric_limits<int>::min()/2};
    }

    static const bool check(T &current, T &x)
    {
        return current <= x;
    }
};

int solve()
{
    ll n, q;
    scanf("%lld", &n);
    scanf("%lld", &q);
    SegmentTree<monoid> seg(n);
    for (size_t i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        seg.set(i, {a,0,0,-a});
    }
    seg.build();
    cout << seg.query(0,n)[0] << "\n";
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        scanf("%lld", &l);
        scanf("%lld", &r);
        l--;
        r--;
        auto temp = seg[l];
        seg.update(l, seg[r]);
        seg.update(r, temp);
        cout << seg.query(0,n)[0] << "\n";
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
