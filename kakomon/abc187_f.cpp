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
    vector<vector<bool>> edges(N,vector<bool>(N,false));
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        edges[u][v] = true;
        edges[v][u] = true;
    }
    vector<ll> DP(1ll<<N,1000000);
    DP[0] = 0;

    for(int i = 0;i < (1ll<<N);i++){
        vector<ll> nodes;
        for(int j = 0;j < N;j++){
            if (i & (1ll<<j) ){
                nodes.push_back(j);
            }
        }
        ll edge_count = 0;
        for(int j = 0;j < nodes.size();j++){
            for(int k = j+1;k < nodes.size();k++){
                if (edges[nodes[j]][nodes[k]]){
                    edge_count++;
                }
            }
        }
        if (edge_count == nodes.size() * (nodes.size()-1)/2){
            ll others = ((1ll<<N)-1) & (~i);
            DP[i] = 1;
            for(int sub=others;sub;sub=(sub-1)&others){
                DP[sub| i]=min(DP[sub| i],DP[sub] + 1);
            }
        }
    }
    // for(int i = 0;i < 1ll<<N;i++){
    //     cout << i << ":" << DP[i] << endl;
    // }
    cout << DP[(1ll<<N)-1] << endl;
    return 0;

}