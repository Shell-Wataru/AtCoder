#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

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
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<string> G(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> G[i];
    }
    UnionFind uf(n*m);
    vector<pair<ll,ll>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            bool paint = true;
            if (i != 0 && G[i][j] != 'X'){
                map<ll,ll> counts;
                for(auto &p:directions){
                    ll x = i + p.first;
                    ll y = j + p.second;
                    if (0 <= x && x < n && 0 <= y && y < m && G[x][y] == 'X'){
                        counts[uf.find(m * x + y)]++;
                        if (counts[uf.find(m * x + y)] >= 2){
                            paint = false;
                            break;
                        }
                    }
                }
            }

            if (paint){
                G[i][j] = 'X';
                for(auto &p:directions){
                    ll x = i + p.first;
                    ll y = j + p.second;
                    if (0 <= x && x < n && 0 <= y && y < m && G[x][y] == 'X'){
                        uf.unite(m*x + y,m*i+j);
                    }
                }
            }
        }
    }
    for(auto s:G){
        cout << s << "\n";
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
    cout << flush;
    return 0;
}
