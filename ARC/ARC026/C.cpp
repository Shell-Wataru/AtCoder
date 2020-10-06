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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

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
            node[k] = min(lazy[k], node[k]);
            if (r - l > 1)
            {
                lazy[k * 2 + 1] = min(lazy[k],lazy[k * 2 + 1]);
                lazy[k * 2 + 2] = min(lazy[k],lazy[k * 2 + 2]);
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
            lazy[k] = min(lazy[k],x);
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
    ll N, L;
    cin >> N >> L;
    vector<vector<ll>> lights(N, vector<ll>(3, 0));
    LazySegmentTree seg(vector<ll>(L + 1, numeric_limits<ll>::max()));
    seg.update(0, 1, 0);
    for (ll i = 0; i < N; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a++;
        b++;
        lights[i] = vector<ll>({a, b, c});
    }

    sort(lights.begin(), lights.end());
    for (auto &l : lights)
    {
        ll min_cost = seg.find(l[0] - 1, l[1]) + l[2];
        seg.update(l[0],l[1],min_cost);
        // cout << l[0] << "~" << l[1] << ":" <<l[2] << endl;
        // for(ll i = 0; i <= L;i++){
        //     cout << seg.find(i,i+1) << ",";
        // }
        // cout << endl;
    }

    cout << seg.find(L,L+1) << endl;
    return 0;
}