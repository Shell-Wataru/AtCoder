#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<ll, ll>>> G(N);
    vector<vector<ll>> Edges(M);
    for (int i = 0; i < M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        Edges[i] = {a, b, c};
    }
    vector<ll> E(K);
    for (int i = 0; i < K; i++)
    {
        cin >> E[i];
        E[i]--;
    }
    ll ans = numeric_limits<ll>::max();
    vector<ll> min_d(N, numeric_limits<ll>::max() / 2);
    min_d[0] = 0;
    for (int i = 0; i < K; i++)
    {
        min_d[Edges[E[i]][1]] = min(min_d[Edges[E[i]][1]], min_d[Edges[E[i]][0]] + Edges[E[i]][2]);
    }
    ans = min_d[N - 1];
    if (ans == numeric_limits<ll>::max() / 2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}