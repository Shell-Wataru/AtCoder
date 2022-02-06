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
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    ll M;
    cin >> M;
    vector<vector<bool>> B(N + 1, vector<bool>(N, true));
    for (int i = 0; i < M; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        B[y][x] = false;
        B[x][y] = false;
    }
    vector<vector<ll>> DP(1ll << N, vector<ll>(N + 1, numeric_limits<ll>::max() / 2));
    cout << numeric_limits<ll>::max() << endl;
    DP[0][N] = 0;
    for (int i = 0; i < (1ll << N) - 1; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (!(i & 1ll << k) && B[j][k])
                {
                    DP[i | 1ll << k][k] = min(DP[i | 1ll << k][k], DP[i][j] + A[k][__builtin_popcountll(i)]);
                }
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < N; i++)
    {
        cout << DP[(1ll << N) - 1][i] << endl;
        ans = min(ans, DP[(1ll << N) - 1][i]);
    }
    cout << ans << endl;
    return 0;
}
