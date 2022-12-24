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

ll answer(vector<vector<vector<ll>>> &G,vector<ll> &fromEnd,ll s,ll t, ll l, ll r){
    if (l+1 == r){
        return r;
    }
    // cout << l << "~" << r << endl;
    ll n = G.size();
    ll center = (l+r)/2;
    vector<ll> fromStart(n,numeric_limits<ll>::max());
    vector<ll> max_d(n,0);
    priority_queue<vector<ll>,vector<vector<ll>> ,greater<vector<ll>>> q;
    q.push({0,s});

    while(!q.empty()){
        ll d = q.top()[0];
        ll current = q.top()[1];
        ll max_sleeped = q.top()[2];
        q.pop();
        if (d >= fromStart[current]){
            continue;
        }
        fromStart[current] = d;
        max_d[current] = max_sleeped;
        if (current == t){
            break;
        }
        for(auto e:G[current]){
            if (d+e[1] < fromStart[e[0]] &&
                d+e[1] + fromEnd[e[0]] <= center &&
                d+e[3]+fromEnd[e[2]] <= center){
                q.push({d+e[1],e[0],max(max_sleeped,d+e[3] + fromEnd[e[2]])});
            }
        }
    }
    if (fromStart[t] <= center){
        return answer(G,fromEnd,s,t,max(fromStart[t]-1,l),min(center,max_d[t]));
    }else{
        return answer(G,fromEnd,s,t,center,r);
    }
}

int solve()
{
    ll N, M,src,dist;
    cin >> N >> M >> src  >> dist;
    vector<vector<vector<ll>>> G(N);
    for(int i = 0;i < M;i++){
        ll L;
        scanf("%lld",&L);
        vector<ll> s(L);
        vector<ll> w(L-1);
        ll line_total = 0;
        for(int j = 0;j < L;j++){
            scanf("%lld",&s[j]);
        }
        for(int j = 0;j < L-1;j++){
            scanf("%lld",&w[j]);
            line_total += w[j];
        }
        ll to_s = 0;
        ll to_end = line_total;
        for(int j = 0;j < L;j++){
            if (j < L -1){
                G[s[j]].push_back({s[j+1],w[j],s[L-1],to_end});
            }
            if (j > 0){
                G[s[j]].push_back({s[j-1],w[j-1],s[0],to_s});
            }
            if (j < L-1){
                to_s += w[j];
                to_end -= w[j];
            }
        }
    }
    vector<ll> fromEnd(N,numeric_limits<ll>::max());
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,dist});
    while(!q.empty()){
        ll d = q.top().first;
        ll current = q.top().second;
        q.pop();
        if (d >= fromEnd[current]){
            continue;
        }
        fromEnd[current] = d;
        for(auto e:G[current]){
            if (d+e[1] < fromEnd[e[0]]){
                q.push({d+e[1],e[0]});
            }
        }
    }
    ll max_d = 0;
    for(int i = 0;i < N;i++){
        max_d = max(max_d,fromEnd[i]);
    }
    cout << answer(G,fromEnd,src,dist,fromEnd[src]-1,numeric_limits<ll>::max()) << endl;
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
