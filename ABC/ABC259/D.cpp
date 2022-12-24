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
#include <stack>

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
  ll N,sx,sy,tx,ty;
  cin >> N >> sx>> sy>> tx >> ty;
  vector<vector<ll>> P(N+2,vector<ll>(3));
  for(int i = 0;i < N;i++){
    cin >> P[i][0] >> P[i][1] >> P[i][2];
  }
  P[N] = {sx,sy,0};
  P[N+1] = {tx,ty,0};
  UnionFind uf(N+2);
  for(int i = 0;i < N+2;i++){
    for(int j = 0;j < N+2;j++){
      ll dx = P[i][0] - P[j][0];
      ll dy = P[i][1] - P[j][1];
      ll d_sum = P[i][2] + P[j][2];
      ll d_sub = abs(P[i][2] - P[j][2]);
      if (dx *dx + dy* dy <= d_sum*d_sum && dx *dx + dy* dy >= d_sub*d_sub){
        uf.unite(i,j);
      }
    }
  }
  if (uf.same(N,N+1)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
