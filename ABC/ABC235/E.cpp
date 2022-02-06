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

int main()
{
  ll N,M,Q;
  cin >> N >> M >> Q;
  priority_queue<vector<ll>,vector<vector<ll>>, greater<vector<ll>>> q;
  for(int i = 0;i < M;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    q.push({c,0,a,b});
  }
  // cout << "!!" << endl;
  map<vector<ll>,bool> answers;
  vector<vector<ll>> queries;
  for(int i = 0;i < Q;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    q.push({c,1,a,b});
    queries.push_back({c,a,b});
  }
  // cout << "!!" << endl;
  UnionFind uf(N);
  while(!q.empty()){
    ll c = q.top()[0];
    ll t = q.top()[1];
    ll a = q.top()[2];
    ll b = q.top()[3];
    q.pop();
    if (t == 0){
      uf.unite(a,b);
    }else{
      // cout << c << endl;
      if (uf.same(a,b)){
        answers[{c,a,b}] = false;
      }else{
        answers[{c,a,b}] = true;
      }
    }
  }
  for(int i = 0;i < Q;i++){
    if (answers[queries[i]]){
      cout << "Yes" << "\n";
    }else{
      cout << "No" << "\n";
    }
  }
  cout << flush;
  return 0;
}
