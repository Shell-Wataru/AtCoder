#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;
using ll = long long;

//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
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

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int solve()
{
    ll n;
    cin >> n;
    UnionFind uf(2*n);
    vector<vector<ll>> D(n,vector<ll>(n,numeric_limits<ll>::max()/2));
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < n;j++){
            if (s[j] == '1'){
                uf.unite(2*i,2*j+1);
                uf.unite(2*i+1,2*j);
                D[i][j] = 1;
            }
        }
    }
    bool is_bartile = true;
    for(int i = 0;i < n;i++){
        if (uf.same(2*i,2*i+1)){
            is_bartile = false;
        }
    }

    warshall_floyd(n,D);
    ll max_d = 0;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            max_d = max(D[i][j],max_d);
        }
    }
    if (is_bartile){
        cout << max_d + 1 << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
