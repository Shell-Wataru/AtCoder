#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000000;
vector<pair<ll,ll>> directions = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

string solve()
{
    ll R,C;
    cin >> R >> C;
    vector<vector<ll>> G(R,vector<ll>(C));
    vector<vector<bool>> visited(R,vector<bool>(C,false));
    priority_queue<pair<ll,ll>> q;
    for(ll i = 0;i < R;i++){
        for (ll j = 0; j < C; j++)
        {
            cin >> G[i][j];
            q.emplace(G[i][j],C*i+j);
        }
    }
    ll ans = 0;
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        ll i = p.second/C;
        ll j = p.second % C;
        ll h = p.first - G[i][j];
        // cout << i << "," << j << ":" << h << endl;
        ans += max(h,0ll);
        G[i][j] = max(p.first ,G[i][j]);
        if (!visited[i][j] || h > 0){
            visited[i][j] = true;
            for(auto &d:directions){
                ll next_i = i+ d.first;
                ll next_j = j+ d.second;
                if (0 <= next_i && next_i < R &&
                    0 <= next_j && next_j < C &&
                    G[next_i][next_j] < G[i][j] - 1){
                    q.emplace(G[i][j]-1,next_i * C + next_j);
                }
            };
        }
    }
    return to_string(ans);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}