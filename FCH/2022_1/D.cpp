#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>
#include <unordered_map>

using namespace std;
using ll = long long;

string solve()
{
    ll N,M,Q;
    scanf("%lld",&N);
    scanf("%lld",&M);
    scanf("%lld",&Q);
    unordered_map<ll,unordered_map<ll,ll>> cache;

    vector<vector<pair<ll,ll>>> G(N);
    for(int i = 0;i < M;i++){
        ll u,v,c;
        scanf("%lld",&u);
        scanf("%lld",&v);
        scanf("%lld",&c);
        u--;v--;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    for(int i = 0;i < N;i++){
        sort(G[i].begin(),G[i].end());
    }
    string ans;
    for(int i = 0;i < Q;i++){
        if (i != 0){
            ans += ' ';
        }
        ll x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        x--;
        y--;
        if (x > y){
            swap(x,y);
        }
        if(cache[x].count(y) == 1){
            ans += to_string(cache[x][y]);
            continue;
        }

        ll a = 0;
        ll b = 0;
        ll flow = 0;
        ll direct_index = lower_bound(G[x].begin(),G[x].end(),make_pair(y,0ll)) - G[x].begin();
        if (direct_index < G[x].size() && G[x][direct_index].first == y){
            flow += G[x][direct_index].second * 2;
        }
        while(a < G[x].size() && b < G[y].size()){
            if (G[x][a].first == G[y][b].first){
                flow += min(G[x][a].second,G[y][b].second);
                a++;
                b++;
            }else if (G[x][a] < G[y][b]){
                a = lower_bound(G[x].begin()+a,G[x].end(),make_pair(G[y][b].first,0ll)) - G[x].begin();
            }else{
                b = lower_bound(G[y].begin()+b,G[y].end(),make_pair(G[x][a].first,0ll)) - G[y].begin();
            }
        }
        cache[x][y] = flow;
        ans += to_string(flow);
    }
    return ans;
}

int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans + "\n";
    }
    cout << flush;
    return 0;
}