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
#include <stack>
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
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> d(N,vector<ll>(N,numeric_limits<ll>::max()/2));
    for(int i = 0;i < N;i++){
        d[i][i] = 0;
    }

    for(int i = 0;i < M;i++){
        ll u,v,t;
        cin >> u >> v >> t;
        u--;v--;
        d[u][v] = t;
        d[v][u] = t;
    }
    warshall_floyd(N,d);
    ll min_d = numeric_limits<ll>::max();
    for(int i = 0;i < N;i++){
        ll max_d = 0;
        for (size_t j = 0; j < N; j++)
        {
            max_d = max(max_d, d[i][j]);
        }
        min_d = min(min_d,max_d);
    }
    cout << min_d << endl;
    return 0;
}