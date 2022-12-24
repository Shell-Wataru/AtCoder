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

vector<pair<ll,ll>> directions = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
void update(vector<vector<ll>> &MinPath,vector<vector<bool>> &removed,ll x,ll y, ll d){
    ll N = MinPath.size();
    if (d < MinPath[x][y]){
        MinPath[x][y] = d;
        for(auto dd:directions){
            ll next_x = x + dd.first;
            ll next_y = y + dd.second;
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N){
                if (removed[next_x][next_y]){
                    update(MinPath,removed,next_x,next_y,d);
                }else{
                    update(MinPath,removed,next_x,next_y,d+1);
                }

            }
        }
    }
}

int solve()
{
    ll N, S;
    cin >> N;
    vector<ll> P(N * N);
    vector<vector<ll>> MinPath(N, vector<ll>(N));
    vector<vector<bool>> removed(N, vector<bool>(N,false));
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            MinPath[i][j] = min(min(i - 0, N - 1 - i), min(j - 0, N - 1 - j));
        }
    }
    // for (ll i = 0; i < N; i++)
    // {
    //     for (ll j = 0; j < N; j++)
    //     {
    //         cout << MinPath[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < N * N; i++)
    {
        cin >> P[i];
        P[i]--;
    }
    ll ans = 0;
    for (int i = 0; i < N * N; i++)
    {
        ll x = P[i] % N;
        ll y = P[i] / N;
        removed[x][y] = true;
        ans += MinPath[x][y];
        update(MinPath,removed,x,y,MinPath[x][y]-1);
    //     for (ll i = 0; i < N; i++)
    // {
    //     for (ll j = 0; j < N; j++)
    //     {
    //         cout << MinPath[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
