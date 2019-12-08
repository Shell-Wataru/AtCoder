#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}


ll dfs(vector<ll> &beauty,map<ll,set<ll>> &edges,vector<bool> &visited,map<ll,ll> &gcds,ll current_node){
    visited[current_node] = true;
    map<ll,ll> next;
    ll total = 0;
    for(auto p:gcds){
        ll current_gcd = gcd(p.first,beauty[current_node]);
        next[current_gcd] += p.second;
        ll addition = p.second * current_gcd % BASE_NUM;
        total = (total + addition) % BASE_NUM;
    }
    next[beauty[current_node]] += 1;
    total = (total + beauty[current_node]) % BASE_NUM;

    for(auto node:edges[current_node]){
        if (!visited[node]){
            total = (total + dfs(beauty,edges,visited,next,node)) % BASE_NUM;
        }
    }

    return total;
};


int main()
{
    ll N;
    vector<ll> beauty;
    map<ll,set<ll>> edges;
    cin >> N ;
    beauty.push_back(0);
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        beauty.push_back(a);
    }


    // cout << "--" << endl;
    for(int i = 0;i< N -1;i++){
        ll a, b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    map<ll,ll> gcds;
    vector<bool> visited(N+1,false);
    ll total = dfs(beauty,edges,visited,gcds,1);
    cout << total << endl;
    return 0;
}