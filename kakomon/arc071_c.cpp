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

struct monoid
{
    using T = char;
    static T op(T l, T r)
    {
        if (l == '-')
        {
            return r;
        }
        if (r == '-')
        {
            return l;
        }
        if (l == 'A' && r == 'A')
        {
            return 'B';
        }
        else if (l == 'A' && r == 'B')
        {
            return '-';
        }
        else if (l == 'B' && r == 'A')
        {
            return '-';
        }
        else if (l == 'B' && r == 'B')
        {
            return 'A';
        }
        return '-';
    }
    static const T id()
    {
        return '-';
    }

    static const bool check(T &current, T &x)
    {
        return current <= x;
    }
};

int main()
{
    string S,T;
    cin >> S >> T;
    ll q;
    cin >> q;
    SegmentTree<monoid> seg_s(S.size());
    SegmentTree<monoid> seg_t(T.size());
    for(int i = 0;i < S.size();i++){
        seg_s.set(i,S[i]);
    }
    seg_s.build();
    for(int i = 0;i < T.size();i++){
        seg_t.set(i,T[i]);
    }
    seg_t.build();
    for(int i = 0;i < q;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        if (seg_s.query(a,b) == seg_t.query(c,d)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    cout << flush;
    return 0;
}