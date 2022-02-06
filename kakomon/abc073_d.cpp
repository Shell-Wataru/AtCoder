#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
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
    ll N,M,R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    vector<vector<ll>> D(N,vector<ll>(N,numeric_limits<ll>::max()/2));
    for(int i = 0;i < R;i++){
        cin >> r[i];
        r[i]--;
    }
    for(int i = 0;i < M;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        D[a][b] = c;
        D[b][a] = c;
    }
    warshall_floyd(N,D);
    vector<vector<ll>> DP(R,vector<ll>(1ll<<R,numeric_limits<ll>::max()));
    for(int i = 0;i < R;i++){
        DP[i][1ll<<i] = 0;
    }
    // cout << "!!!" << endl;
    for(int i = 1;i < 1ll<<R;i++){
        for(int j = 0;j < R;j++){
            if (i & 1ll<<j){
                for(int k = 0;k < R;k++){
                    if (!(i & 1ll<<k)){
                        DP[k][i | 1ll<<k] = min(DP[k][i | 1ll<<k],DP[j][i]+ D[r[j]][r[k]]);
                    }
                }
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < R;i++){
        ans = min(ans,DP[i][(1ll<<R)-1]);
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
