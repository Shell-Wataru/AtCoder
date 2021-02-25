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

bool valid(ll current,ll d,vector<vector<pair<ll,ll>>> &G,vector<bool> &visited,vector<ll> &D){
    if (visited[current]){
        return d == D[current];
    }
    visited[current] = true;
    D[current] = d;
    bool all_valid = true;
    for(auto &p:G[current]){
        all_valid = all_valid && valid(p.first,p.second + d,G,visited,D) ;
    }
    return all_valid;
}

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> G(N);
    vector<ll>  D(N);
    vector<bool>  visited(N,false);
    for(int i = 0;i < M;i++){
        ll l,r,d;
        cin >> l >> r >> d;
        l--;
        r--;
        G[l].emplace_back(r,d);
        G[r].emplace_back(l,-d);
    }
    bool all_valid = true;
    for(int i = 0;i < N;i++){
        if (!visited[i]){
            all_valid = all_valid && valid(i,0,G,visited,D);
        }
    }
    if (all_valid){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}