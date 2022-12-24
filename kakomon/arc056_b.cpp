#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{

    ll N,M,S;
    cin >> N >> M >> S;
    vector<vector<ll>> G(N);
    vector<ll> maxmin_path(N,numeric_limits<ll>::min());
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    priority_queue<pair<ll,ll>> q;
    q.push({S-1,S-1});
    while(!q.empty()){
        ll current = q.top().second;
        ll min_path = q.top().first;
        q.pop();
        if (maxmin_path[current] < min_path){
            maxmin_path[current] = min_path;
            for(auto to:G[current]){
                q.push({min(to,min_path),to});
            }
        }
    }
    for(int i = 0;i < N;i++){
        // cout << maxmin_path[i] << "\n";
        if (maxmin_path[i] == i){
            cout << i + 1 << "\n";
        }
    }
    cout << flush;
    return 0;
}
int main()
{
    //   int t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}