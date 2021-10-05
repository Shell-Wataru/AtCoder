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

void dfs(vector<vector<ll>> &G,vector<ll> &points,ll current, ll parent){
    if (parent != -1){
        points[current] += points[parent];
    }
    for(auto to:G[current]){
        if (to != parent){
            dfs(G,points,to,current);
        }
    }
}
int main()
{
    // 整数の入力
    ll N,Q;
    cin >> N >> Q;
    vector<vector<ll>> G(N);
    vector<ll> points(N,0);
    for(int i = 0;i < N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 0;i < Q;i++){
        ll p,x;
        cin >> p >> x;
        p--;
        // cout << x << endl;
        points[p] += x;
    }
    // for(int i= 0;i < N;i++){
    //     cout << points[i] << ",";
    // }
    // cout << endl;
    dfs(G,points,0,-1);
    for(int i = 0;i < N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << points[i];
    }
    cout << endl;
    return 0;
}