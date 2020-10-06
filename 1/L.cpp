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
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;
// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
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

    template <typename C>
    int find_subtree(int a, const C &check, T &M, bool type)
    {
        while (a < sz)
        {
            T nxt = type ? Monoid::op(seg[2 * a + type], M) : Monoid::op(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check)
    {
        T L = id;
        if (a <= 0)
        {
            if (check(f(L, seg[1])))
                return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
            {
                T nxt = Monoid::op(L, seg[a]);
                if (check(nxt))
                    return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check)
    {
        T R = id;
        if (b >= sz)
        {
            if (check(f(seg[1], R)))
                return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (b & 1)
            {
                T nxt = Monoid::op(seg[--b], R);
                if (check(nxt))
                    return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

struct monoid_max_with_index
{
    using T = pair<ll, ll>;
    static T op(T l, T r)
    {
        if (l.first < r.first)
        {
            return r;
        }
        else if (l.first > r.first)
        {
            return l;
        }
        else
        {
            return l;
        }
    }
    static const T id()
    {
        return {0, -1};
    }
};

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<queue<ll>> qs(N);
    SegmentTree<monoid_max_with_index> seg1(N);
    SegmentTree<monoid_max_with_index> seg2(N);
    for (int i = 0; i < N; i++)
    {
        ll K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            ll t;
            cin >> t;
            qs[i].push(t);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!qs[i].empty())
        {
            seg1.set(i, {qs[i].front(), i});
        }
        qs[i].pop();
        if (!qs[i].empty())
        {
            seg2.set(i, {qs[i].front(), i});
        }
        qs[i].pop();
    }
    seg1.build();
    seg2.build();
    ll M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        // cout << i  << ":" << endl;
        ll a;
        cin >> a;
        ll max_index = -1;
        ll max_item = -1;
        ll max_row = -1;
        if (a == 1)
        {
            auto p = seg1.query(0, N);
            max_index = p.second;
            max_item = p.first;
            max_row = 0;
        }
        else
        {
            auto p1 = seg1.query(0, N);
            auto p2 = seg2.query(0, N);
            if (p1.first > p2.first)
            {
                max_index = p1.second;
                max_item = p1.first;
                max_row = 0;
            }
            else
            {
                max_index = p2.second;
                max_item = p2.first;
                max_row = 1;
            }
        }
        cout << max_item << endl;
        // cout << max_index << endl;
        // cout << max_row << endl;
        if (max_row == 0)
        {
            // cout << "!" << endl;
            seg1.update(max_index, seg2[max_index]);
        }
        if (!qs[max_index].empty())
        {
            // cout << "?" << endl;
            seg2.update(max_index, {qs[max_index].front(), max_index});
            qs[max_index].pop();
        }
        else
        {
            // cout << "=" << endl;
            seg2.update(max_index, {0, max_index});
        }
    }
    // cout << "fnish" << endl;
    return 0;
}