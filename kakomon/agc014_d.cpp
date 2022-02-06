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

int main()
{
    ll N;
    cin >> N;
    vector<set<ll>> G(N);
    for(int n = 0;n < N -1;n++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    vector<ll> neighbor_edge_count(N,0);
    bool found = false;
    queue<ll> near_edges;
    for(int i = 0;i < N;i++){
        if (G[i].size() == 1){
            neighbor_edge_count[*G[i].begin()]++;
            if (G[*G[i].begin()].size() == 2){
                near_edges.push(*G[i].begin());
            }
            if (neighbor_edge_count[*G[i].begin()] >= 2){
                found = true;
            }
        }
    }
    while(!near_edges.empty()){
        ll e = near_edges.front();
        near_edges.pop();
        for(auto to:G[e]){
            G[to].erase(e);
            if (G[to].size() == 1){

                neighbor_edge_count[*G[to].begin()]++;
                if (G[*G[to].begin()].size() == 2){
                    near_edges.push(*G[to].begin());
                }
                if (neighbor_edge_count[*G[to].begin()] >= 2){
                    found = true;
                }
            }else if (G[to].size() == 2){
                for(auto toto:G[to]){
                    if (G[toto].size() == 1){
                        near_edges.push(to);
                        break;
                    }
                }
            }
        }
        G[e].clear();
    }
    if (found){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    return 0;
}