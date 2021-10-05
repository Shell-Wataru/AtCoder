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

ll find_max(vector<vector<ll>> &G,vector<ll> &A ,vector<ll> &maxA,ll current){
    if (maxA[current] != numeric_limits<ll>::min()){
        return maxA[current];
    }
    // cout << current << ":";
    for(auto to:G[current]){
        // cout << to << ",";
        maxA[current] = max(maxA[current], A[to]);
        maxA[current] = max(maxA[current], find_max(G,A,maxA,to));
    }
    // cout << endl;
    return maxA[current];
}

ll find_min(vector<vector<ll>> &G,vector<ll> &A,vector<ll> &minA,ll current){
    if (minA[current] != numeric_limits<ll>::max()){
        return minA[current];
    }
    minA[current] = min(minA[current],A[current]);
    for(auto to:G[current]){
        minA[current] = min(minA[current], find_min(G,A,minA,to));
    }
    return minA[current];
}
int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<vector<ll>> G(N);
    vector<vector<ll>> invG(N);
    vector<ll> minA(N,numeric_limits<ll>::max());
    vector<ll> maxA(N,numeric_limits<ll>::min());
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        invG[v].push_back(u);
    }

    for(int i = 0;i < N;i++){
        find_max(G,A,maxA,i);
    }

    for(int i = N-1;i >= 0;i--){
        find_min(invG,A,minA,i);
    }
    ll ans = numeric_limits<ll>::min();
    for(int i = 0;i < N;i++){
        // cout << maxA[i] << " " << minA[i] << endl;
        if (maxA[i] != numeric_limits<ll>::min() && minA[i] != numeric_limits<ll>::max()){
            ans = max(ans,maxA[i] - minA[i]);
        }
    }
    cout << ans << endl;
    return 0;
}