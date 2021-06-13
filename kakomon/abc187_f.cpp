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
    vector<bool> edges(N*N,false);
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        edges[N*u + v] = true;
        edges[N*v + u] = true;
    }
    vector<ll> DP(1ll<<N,1000000);
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
                if (edges[N*nodes[j]+nodes[k]]){
                    edge_count++;
                }
            }
        }
        if (edge_count == nodes.size() * (nodes.size() - 1) /2){
            DP[i] = 1;
        }else if (edge_count == nodes.size() * (nodes.size() - 1) /2 - 1){
            DP[i] = 2;
        }else if (edge_count == 0){
            DP[i] = nodes.size();
        }else if (edge_count == 1){
            DP[i] = nodes.size() - 1;
        }else{
            for(int j = 1;j < (1ll<<((ll)nodes.size()-1));j++){
                ll a = 0;
                ll b = 0;
                for(int k = 0;k < nodes.size();k++){
                    if (j & 1ll<<k){
                        a += 1ll<<nodes[k];
                    }else{
                        b += 1ll<<nodes[k];
                    }
                }
                DP[i] = min(DP[i],DP[a] + DP[b]);
            }
        }
    }
    // for(int i = 0;i < 1ll<<N;i++){
    //     cout << i << ":" << DP[i] << endl;
    // }
    cout << DP[(1ll<<N)-1] << endl;
    return 0;

}