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

int solve()
{
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G1(N);
    vector<vector<ll>> G2(N);
    for(int i = 0;i < M;i++){
        ll c,a,b;
        cin >> c >> a >> b;
        // a--;
        // b--;
        if (c == 0){
            G1[a].push_back(b);
            G1[b].push_back(a);
        }else{
            G2[a].push_back(b);
            G2[b].push_back(a);
        }
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<pair<ll,ll>>> q1;
    queue<pair<ll,ll>> q2;
    vector<ll> Distances(N,numeric_limits<ll>::max());
    q1.push({0,0});
    // cout << "!" << endl;
    for(int i = 1;i <= N;i++){
        while(!q1.empty()){
            ll current = q1.top().second;
            ll d = q1.top().first;
            q1.pop();
            if (Distances[current] <= d){
                continue;
            }
            Distances[current] = d;
            q2.push({d,current});
            for(auto to:G1[current]){
                if (d+1 < Distances[to]){
                    q1.push({d+1,to});
                }
            }
        }
        while(!q2.empty()){
            ll current = q2.front().second;
            ll d = q2.front().first;
            q2.pop();
            for(auto to:G2[current]){
                if (d+i < Distances[to]){
                    q1.push({d+i,to});
                }
            }
        }
    }
    for(int i = 0;i < N;i++){
        cout << Distances[i] << "\n";
    }
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
