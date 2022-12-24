#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    SegmentTree<monoid_min> seg(N);
    for (ll i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        seg.set(i, {a, i});
    }
    seg.build();
    ll last = -1;
    ll ans = 1;
    // cout << seg.query(0, N).first << endl;
    while (seg.query(0, N).first != numeric_limits<ll>::max())
    {
        auto p = seg.query(last + 1, N);
        // cout << "!" << p.first << " " << p.second << endl;
        if (p.first == numeric_limits<ll>::max())
        {
            last = -1;
            ans++;
        }
        else
        {
            last = p.second;
            seg.update(p.second, {numeric_limits<ll>::max(), p.second});
        }
    }
    cout << ans << endl;
    return 0;
}