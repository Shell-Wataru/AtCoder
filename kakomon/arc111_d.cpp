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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;


ll dfs(ll current,ll parent,vector<vector<ll>> &G,vector<ll> &c,vector<string> &answers,map<pair<ll,ll>,ll> &edge_indices,vector<bool> &visited){
    if(visited[current]){
        return 0;
    }
    visited[current] = true;
    for(auto to:G[current]){
        if (to != parent){
            if (c[to] < c[current]){
                if (edge_indices.count({current,to})){
                    answers[edge_indices[{current,to}]] = "->";
                }else{
                    answers[edge_indices[{to,current}]] = "<-";
                }
            }else if (c[to] == c[current]){
                if (edge_indices.count({current,to})){
                    if (answers[edge_indices[{current,to}]].empty()){
                        answers[edge_indices[{current,to}]] = "->";
                        dfs(to,current,G,c,answers,edge_indices,visited);
                    }
                }else{
                    if (answers[edge_indices[{to,current}]].empty()){
                        answers[edge_indices[{to,current}]] = "<-";
                        dfs(to,current,G,c,answers,edge_indices,visited);
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    vector<pair<ll,ll>> edges(M);
    map<pair<ll,ll>,ll> edge_indexes;
    vector<string> answers(M,"");
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edges[i]={u,v};
        edge_indexes[{u,v}] = i;
    }
    vector<ll> c(N);
    priority_queue<pair<ll,ll>> q;
    for(int i = 0;i < N;i++){
        cin >> c[i];
        q.push({c[i],i});
    }
    vector<bool> visited(N,false);
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        dfs(p.second,-1,G,c,answers,edge_indexes,visited);
    }

    for(auto s:answers){
        cout << s << endl;
    }
    return 0;
}
