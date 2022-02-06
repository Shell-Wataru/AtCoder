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

struct monoid_min_with_edge_and_index
{
    using T = vector<ll>;
    static T op(T &l, T &r) { return min(l, r); }
    static const T id()
    {
        return {numeric_limits<ll>::max(), -1, -1, -1};
    }

    static const bool check(T &current, T &x)
    {
        return current >= x;
    }
};

void four_vertices_min_distance(SegmentTree<monoid_min_with_edge_and_index> &seg)
{
    vector<vector<ll>> candidates;
    for (int i = 0; i < 4; i++)
    {
        candidates.push_back(seg.query(0, seg.sz));
        seg.update(candidates.back()[1], monoid_min_with_edge_and_index::id());
    }
    vector<ll> ans;
    ll min_distance = numeric_limits<ll>::max();
    for (int i = 0; i < 4; i++)
    {
        cout << candidates[i][1] << endl;
        for (int j = i + 1; j < 4; j++)
        {
            if (candidates[i][2] != candidates[j][2] &&
                candidates[i][2] != candidates[j][3] &&
                candidates[i][3] != candidates[j][2] &&
                candidates[i][3] != candidates[j][3] &&
                candidates[i][0] + candidates[j][0] < min_distance)
            {
                min_distance = candidates[i][0] + candidates[j][0];
            }
        }
    }
    if (min)
    for (int i = 0; i < 4; i++)
    {
        seg.update(candidates[i][1], candidates[i]);
    }
    cout << min_distance << "\n";
}
int solve()
{
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<vector<ll>> edges(m);
    map<pair<ll,ll>,ll> edge_indices;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        scanf("%lld", &u);
        scanf("%lld", &v);
        scanf("%lld", &w);
        u--;
        v--;
        if (v > u)
        {
            swap(u, v);
        }
        edge_indices[{u,v}] = i;
        edges[i] = {u, v, w};
    }
    ll q;
    scanf("%lld", &q);
    SegmentTree<monoid_min_with_edge_and_index> seg(m + q);
    for (int i = 0; i < m; i++)
    {
        seg.update(i, {edges[i][2], i, edges[i][0], edges[i][1]});
    }
    four_vertices_min_distance(seg);
    for (int i = 0; i < q; i++)
    {
        ll t;
        scanf("%lld", &t);
        if (t == 0)
        {
            ll u, v;
            scanf("%lld", &u);
            scanf("%lld", &v);
            u--;
            v--;
            if (v > u)
            {
                swap(u, v);
            }
            seg.update(edge_indices[{u,v}],monoid_min_with_edge_and_index::id());
            four_vertices_min_distance(seg);
        }
        else
        {
            ll u, v, w;
            scanf("%lld", &u);
            scanf("%lld", &v);
            scanf("%lld", &w);
            u--;
            v--;
            if (v > u)
            {
                swap(u, v);
            }
            seg.update(m+i,{w,m+i,u,v});
            edge_indices[{u,v}] = m+i;
            four_vertices_min_distance(seg);
        }
    }
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
