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

vector<vector<ll>> warshall_floyd(int n, vector<vector<ll>> &G)
{
    vector<vector<ll>> d = G;
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
    return d;
}

bool same(int N, vector<vector<ll>> &d1, vector<vector<ll>> &d2){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if (d1[i][j] != d2[i][j] ){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N,vector<ll>(N,numeric_limits<ll>::max()/2));
    for(int i = 0;i < N;i++){
        G[i][i] = 0;
    }
    for (size_t i = 0; i < M; i++)
    {
        ll u, v,c;
        scanf("%lld",&u);
        scanf("%lld",&v);
        scanf("%lld",&c);
        u--;
        v--;
        G[u][v] = c;
        G[v][u] = c;
    }
    vector<vector<ll>> d = warshall_floyd(N,G);
    ll ans =0;
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
            if (G[i][j] != numeric_limits<ll>::max()/2 && d[i][j] < G[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}