#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

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

int main()
{
    ll n = 5;
    vector<vector<ll>> G = {
        {1,0,1},
        {2,1,2},
        {3,2,0},
        {4,3,4}
    };
    ll m = G.size();
    cout << n << " " << m << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll l;
            cin >> l;
            cerr << l << endl;
            break;
        }else{
            UnionFind uf(n);
            string S;
            cin >> S;
            priority_queue<vector<ll>> q;
            for(int i = 0;i < m;i++){
                if (S[i] == '1'){
                    q.push(G[i]);
                }
            }
            ll ans = 0;
            while(!q.empty()){
                if (uf.unite(q.top()[1],q.top()[2])){
                    // cout << q.top()[0] << endl;
                    ans += q.top()[0];
                }
                q.pop();
            }
            cout << ans << endl;
        }
    }
    return 0;
}
