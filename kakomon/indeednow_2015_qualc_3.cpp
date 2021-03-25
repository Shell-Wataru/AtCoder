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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    vector<bool> added(N);
    set<ll> selectable;
    vector<ll> ans;
    for (int i = 0; i < N - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    selectable.insert(0);
    added[0] = true;
    while (selectable.size() > 0)
    {
        ll from = *(selectable.begin());
        selectable.erase(from);
        ans.push_back(from);
        for (auto to : G[from])
        {
            if (!added[to])
            {
                selectable.insert(to);
                added[to] = true;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << ans[i] + 1;
        ;
    }
    cout << endl;
    return 0;
}