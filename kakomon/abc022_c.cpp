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

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<ll> fromRoot(N, numeric_limits<ll>::max()/2);
    vector<vector<ll>> G(N, vector<ll>(N, numeric_limits<ll>::max()/2));
    for (int i = 0; i < M; i++)
    {
        ll u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        if (u == 0)
        {
            fromRoot[v] = l;
        }
        else if (v == 0)
        {
            fromRoot[u] = l;
        }
        else
        {
            G[u][v] = l;
            G[v][u] = l;
        }
    }
    warshall_floyd(N, G);
    ll ans =numeric_limits<ll>::max();
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (fromRoot[i] == numeric_limits<ll>::max()/2 || fromRoot[j] == numeric_limits<ll>::max()/2 || G[i][j] == numeric_limits<ll>::max()/2){
                continue;
            }
            ans = min(ans,fromRoot[i] + fromRoot[j] + G[i][j]);
        }
    }
    if (ans == numeric_limits<ll>::max()){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}