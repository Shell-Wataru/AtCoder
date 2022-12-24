#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
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

int solve()
{
    ll N, M;
    cin >> N ;
    vector<vector<ll>> G(N, vector<ll>(N, numeric_limits<ll>::max()/2));
    for (int i = 0; i < N-1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = 1ll << i;
        G[b][a] = 1ll << i;
    }
    for(int i = 0;i < N;i++){
        G[i][i] = 0;
    }
    warshall_floyd(N, G);
    // for(int i = 0;i < N;i++){
    //     for(int j = 0;j < N;j++){
    //         cout << G[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    cin >> M;
    vector<pair<ll, ll>> Constraints(M);
    for (ll i = 0; i < M; i++)
    {
        cin >> Constraints[i].first >> Constraints[i].second;
        Constraints[i].first--;
        Constraints[i].second--;
    }
    ll ans = 0;
    for(ll i = 0;i < (1ll<<M);i++){
        ll constraint = 0;
        for(ll j = 0;j < M;j++){
            if (i & 1ll<<j){
                constraint = constraint | G[Constraints[j].first][Constraints[j].second];
            }
        }
        // cout << (1ll<<(N-1-__builtin_popcount(constraint))) << endl;
        if (__builtin_popcountll(i) % 2 == 0){
            ans += 1ll<<(N-1-__builtin_popcountll(constraint));
        }else{
            ans -= 1ll<<(N-1-__builtin_popcountll(constraint));
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    //   // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}