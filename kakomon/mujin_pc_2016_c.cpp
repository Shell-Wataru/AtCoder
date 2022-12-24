#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
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

  void clear(){
    fill(data.begin(),data.end(),-1);
  }
};

int solve()
{
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> Edges(M);
    UnionFind uf(N);
    for(int i = 0;i < M;i++){
        cin >> Edges[i].first >> Edges[i].second;
        Edges[i].first--;
        Edges[i].second--;
    }
    ll ans = 0;
    for(int i = 0;i < 1ll<<(N-1);i++){
        uf.clear();
        for(int j = 0;j < M;j++){
            bool a = (i & (1ll<<Edges[j].first));
            bool b = (i & (1ll<<Edges[j].second));
            // cout << a << "," << b << endl;
            if ( a != b){
                // cout << Edges[j].first << "~" << Edges[j].second <<endl;
                uf.unite(Edges[j].first,Edges[j].second);
            }
        }
        bool is_ok = true;
        for(int j = 0;j < M;j++){
            bool a = (i & (1ll<<Edges[j].first));
            bool b = (i & (1ll<<Edges[j].second));
            if (a == b && !uf.same(Edges[j].first,Edges[j].second)){
                is_ok = false;
            }
        }
        // cout << i << ":" << is_ok    << endl;
        if (is_ok){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}