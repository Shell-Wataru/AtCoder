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
    ll N, M, Q;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<vector<pair<ll, ll>>> colors(N, vector<pair<ll, ll>>(11, {-1, 0}));
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        ll v, d, c;
        cin >> v >> d >> c;
        v--;
        colors[v][d] = max(colors[v][d], {i, c});
    }
    for (int d = 10; d > 0; d--)
    {
        for (int i = 0; i < N; i++)
        {
            for (auto to : G[i])
            {
                colors[to][d-1] = max(colors[to][d-1],colors[i][d]);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        pair<ll,ll> c = {-1,0};
        for(int j = 0;j <= 10;j++){
            c = max(c,colors[i][j]);
        }
        cout << c.second << "\n";
    }
    cout << flush;
    return 0;
}