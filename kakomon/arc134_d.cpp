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
    using T = vector<ll>;
    static T op(T &l, T &r) { return min(l, r); }
    static const T id()
    {
        return {numeric_limits<ll>::max(), numeric_limits<ll>::max(), numeric_limits<ll>::max()};
    }

    static const bool check(T &current, T &x)
    {
        return current <= x;
    }
};

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> a(2 * N);
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> a[i];
    }
    SegmentTree<monoid_min> seg(N);
    for (int i = 0; i < N; i++)
    {
        seg.set(i, {a[i], a[i + N], i});
    }
    seg.build();
    set<ll> indices;
    set<ll> unique_indices;
    while (true)
    {
        // cout << "!!" << endl;
        auto v = seg.query(0, N);
        // cout << v[0] << "," << v[1] << "," << v[2] << endl;
        if (v[0] == numeric_limits<ll>::max())
        {
            break;
        }
        else
        {
            auto iter = indices.lower_bound(v[2]);
            if ((iter == indices.end() || a[v[2]] <= a[*iter]) && (indices.size() == 0 || a[v[2]] < a[*indices.begin() + N] || (a[v[2]] == a[*indices.begin() + N] && unique_indices.size() == 2 && a[*unique_indices.begin()] < a[*unique_indices.rbegin()])))
            {
                // cout << v[2] << endl;
                unique_indices.insert(v[2] + N);
                set<ll> next_unique_indices;
                for (auto i : unique_indices)
                {
                    if (next_unique_indices.size() == 0)
                    {
                        next_unique_indices.insert(i);
                    }
                    else if (a[*next_unique_indices.begin()] != a[i])
                    {
                        next_unique_indices.insert(i);
                        break;
                    }
                }
                unique_indices = next_unique_indices;
                indices.insert(v[2]);
                seg.update(v[2], monoid_min::id());
            }
            else
            {
                seg.update(v[2], monoid_min::id());
            }
        }
    }
    vector<ll> ans;
    for (auto i : indices)
    {
        ans.push_back(a[i]);
    }
    for (auto i : indices)
    {
        ans.push_back(a[i + N]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}