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

using namespace std;

const ll INF = numeric_limits<ll>::max();
struct LazySegmentTree
{
private:
    ll n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<ll> v)
    {
        ll sz = (ll)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, INF);
        lazyFlag.resize(2 * n - 1, false);

        for (ll i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (ll i = n - 2; i >= 0; i--)
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void lazyEvaluate(ll k, ll l, ll r)
    {
        if (lazyFlag[k])
        {
            //ここ修正
            node[k] = min(lazy[k], node[k]);
            if (r - l > 1)
            {
                //ここ修正
                lazy[k * 2 + 1] = min(lazy[k], lazy[k * 2 + 1]);
                lazy[k * 2 + 2] = min(lazy[k], lazy[k * 2 + 2]);
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
        }
    }

    void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            //ここ修正
            lazy[k] = min(lazy[k], x);
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else
        {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll find(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return INF;
        if (a <= l && r <= b)
            return node[k];
        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main()
{
    // 整数の入力
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N - 2, N - 2);
    ll ans = (N - 2) * (N - 2);
    LazySegmentTree vertical(A);
    LazySegmentTree horizontal(A);
    for (int i = 0; i < Q; i++)
    {
        ll t, x;
        cin >> t >> x;
        x -= 2;
        if (t == 1)
        {
            ll depth = vertical.find(x, x + 1);
            // cout << depth << endl;
            ans -= depth;
            horizontal.update(0, depth, x);
        }
        else
        {
            ll depth = horizontal.find(x, x + 1);
            // cout << depth << endl;
            ans -= depth;
            vertical.update(0, depth, x);
        }
    }
    cout << ans << endl;
    return 0;
}