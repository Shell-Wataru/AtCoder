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
    ll n;
    scanf("%lld", &n);
    string a,b;
    cin >> a;
    cin >> b;
    set<pair<ll,ll>,greater<pair<ll,ll>>> data;
    UnionFind uf(26);
    for(int i = 0; i < n;i++){
        data.emplace(b[i] - 'a',a[i] - 'a');
    }
    ll total = 0;
    bool can = true;
    for(auto &p:data){
        if (p.first < p.second){
            can = false;
        }else if(p.first > p.second){
            if (uf.unite(p.first,p.second)){
                total++;
            }
        }
    }
    if (can){
        cout << total << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
