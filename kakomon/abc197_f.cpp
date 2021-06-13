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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<vector<ll>>> G(N,vector<vector<ll>>(26,vector<ll>()));
    vector<bool> edges(N*N,false);
    vector<bool> pushed(N*N,false);
    for(int i = 0;i < N;i++){
        edges[N*i+i]= true;
    }
    for (size_t i = 0; i < M; i++)
    {
        ll a,b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][c - 'a'].push_back(b);
        G[b][c - 'a'].push_back(a);
        edges[N*a+b] = true;
        edges[N*b+a] = true;
    }
    vector<vector<ll>>  DP(N,vector<ll>(N,numeric_limits<ll>::max()/2));
    queue<pair<ll,pair<ll,ll>>> q;
    q.push({0,{0,N-1}});
    ll ans = numeric_limits<ll>::max()/2;
    while(!q.empty()){
        auto d = q.front();
        q.pop();
        ll value = d.first;
        ll from = d.second.first;
        ll to = d.second.second;
        if (ans <= 2 *value){
            break;
        }
        if (value > DP[from][to]){
            continue;
        }
        DP[from][to] = value;
        if (!edges[N*from+to]){
            for(int i = 0;i < 26;i++){
                for(auto to1:G[from][i]){
                    for(auto to2:G[to][i]){
                        if (value+1 < DP[to1][to2] && !pushed[N*to1+to2]){
                            q.push({value+1,{to1,to2}});
                            pushed[N*to1+to2] = true;
                        }
                    }
                }
            }
        }else{
            if (from == to){
                ans = min(ans,2*value);
            }else{
                ans = min(ans,2*value+1);
            }
        }
    }
    if (ans == numeric_limits<ll>::max()/2){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;

}