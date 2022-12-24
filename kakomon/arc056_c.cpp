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


vector<ll> score_cache(1ll<<17);
ll dfs(ll can_use, vector<vector<ll>> &W, ll K, ll current_score)
{
    if (can_use == 0){
        return current_score;
    }
    ll n = W.size();
    ll max_bit = 63 - __builtin_clzll(can_use);
    ll sub_can_use = can_use & ~(1ll << max_bit);
    // cout << bitset<4>(can_use) << endl;
    // cout << bitset<4>(sub_can_use) << endl;
    ll ans = 0;
    for (int sub = sub_can_use; true; sub = (sub - 1) & sub_can_use)
    {
        ll group = sub | (1ll<<max_bit);
        ans = max(ans,dfs(can_use & ~group,W,K,current_score + K + score_cache[group]));
        if (sub == 0){
            break;
        }
    }
    return ans;
}

int solve()
{
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> W(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }
    ll total = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            total += W[i][j];
        }
    }
    for(int group = 0;group < 1ll<<N;group++){
        ll score = 0;
        for(int i = 0;i < N;i++){
            if (group & 1ll<<i){
                for(int j = i+1;j < N;j++){
                    if (group & 1ll<<j){
                        score += W[i][j];
                    }
                }
            }
        }
        score_cache[group] = score;
    }
    vector<ll> DP(1ll<<N,0);
    for(int can_use = 1;can_use < 1ll<<N;can_use++){
        ll max_bit = 63 - __builtin_clzll(can_use);
        ll sub_can_use = can_use & ~(1ll << max_bit);
        // cout << bitset<4>(can_use) << endl;
        // cout << bitset<4>(sub_can_use) << endl;
        ll ans = 0;
        for (int sub = sub_can_use; true; sub = (sub - 1) & sub_can_use)
        {
            ll group = sub | (1ll<<max_bit);
            DP[can_use] = max(DP[can_use],DP[can_use & ~group] + K + score_cache[group]);
            if (sub == 0){
                break;
            }
        }
    }
    cout << DP[(1ll<<N) - 1] - total << endl;
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
    // cout << flush;
    return 0;
}
