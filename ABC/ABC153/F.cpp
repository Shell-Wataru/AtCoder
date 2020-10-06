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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

struct LazySegmentTree
{
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v)
    {
        int sz = (int)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(int k, int l, int r)
    {
        if (lazy[k] != 0)
        {
            node[k] += lazy[k];
            if (r - l > 1)
            {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return 0;
        if (a <= l && r <= b)
            return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

int main()
{
    // 整数の入力
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pair<ll, ll>> monsters;
    for (int i = 0; i < N; i++)
    {
        ll x, h;
        cin >> x >> h;
        monsters.push_back({x, h});
    }
    sort(monsters.begin(), monsters.end());
    vector<ll> initial_hp;
    for (int i = 0; i < N; i++)
    {
        initial_hp.push_back(monsters[i].second);
    }
    LazySegmentTree seg(initial_hp);
    ll index = 0;
    ll count = 0;
    while (index < N)
    {
        ll current = seg.getsum(index, index + 1);
        if (current <= 0)
        {
            index++;
            continue;
        }
        else
        {

            pair<ll, ll> to_monster = {monsters[index].first + 2 * D + 1, 0};
            ll to = lower_bound(monsters.begin(), monsters.end(), to_monster) - monsters.begin();
            // cout << "i:" << index << ",to:" << to << "current" << current << endl;
            ll attacks = (current + A - 1) / A;
            count += attacks;
            seg.add(index, to, -A * attacks);
            index++;
        }
    }
    cout << count << endl;
    return 0;
}