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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

int solve()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N,vector<bool>(N,true));
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u][v] = false;
        G[v][u] = false;
    }
    UnionFind uf(2*N);
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
            if (G[i][j]){
                uf.unite(2*i,2*j+1);
                uf.unite(2*i+1,2*j);
            }
        }
    }
    map<ll,pair<ll,ll>> counts;
    for(int i = 0;i < N;i++){
        if (uf.same(2*i,2*i+1)){
            cout << -1 << endl;
            return 0;
        }
        if (uf.find(2*i) < uf.find(2*i+1)){
            counts[uf.find(2*i)].first++;
        }else{
            counts[uf.find(2*i+1)].second++;
        }
    }
    ll amari = N;
    // cout << "!" << endl;
    vector<bool> diff(N+1,false);
    diff[0] = true;
    for(auto p: counts){
        // cout << p.second.first << "," << p.second.second << endl;
        amari -=p.second.first + p.second.second;
        vector<bool> next_diff(N+1,false);
        for(int i = 0;i <= N;i++){
            if (diff[i]){
                next_diff[abs(i + p.second.first - p.second.second)] = true;
                next_diff[abs(i - p.second.first + p.second.second)] = true;
            }
        }
        diff = next_diff;
    }
    ll min_diff = numeric_limits<ll>::max();
    for(int i = 0;i <= N;i++){
        if (diff[i]){
            if(i - amari >= 0){
                min_diff = min(min_diff,i-amari);
            }else if ( (amari - i) % 2 == 0 ){
                min_diff = min(min_diff,0ll);
            }else{
                min_diff = min(min_diff,1ll);
            }
        }
    }
    ll reds = (N + min_diff)/2;
    ll blues = (N - min_diff)/2;
    cout << reds*(reds-1)/2 + blues*(blues-1)/2 << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // while(T--){
    solve();
    // }
    return 0;
}
