#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll n, m;
    vector<pair<ll, ll>> edges;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        edges.push_back(make_pair(a, b));
    }
    if (n <= 6)
    {
        cout << m << endl;
    }
    else
    {
        vector<ll> v{1, 1, 2, 3, 4, 5, 6};
        ll max_edges = 0;
        do
        {
            set<pair<ll, ll>> a;
            for (auto e : edges)
            {
                ll v1 = v[e.first - 1];
                ll v2 = v[e.second - 1];
                ll vmin = min(v1, v2);
                ll vmax = max(v1, v2);

                a.insert(make_pair(vmin, vmax));
            }
            if (a.size() > max_edges)
            {
                max_edges = a.size();
            }

        } while (std::next_permutation(v.begin(), v.end()));
        cout << max_edges << endl;
    }
    return 0;
}
