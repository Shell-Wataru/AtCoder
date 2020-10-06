#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
#include <random>
using namespace std;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
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

vector<vector<float>> Projector(int k){
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::normal_distribution<> dist(0.0, 1.0);

  vector<vector<float>> U(200,vector<float>(k));
  for(int i = 0;i < k;i++){
    for(int j = 0;j < 200;j++){
      U[i][j] = dist(engine);
    }

    float size = 0;
    for(int j= 0;j < 200;j++){
      size += U[i][j] * U[i][j];
    }

    for(int j= 0;j < 200;j++){
      U[i][j] /= sqrt(size);
    }
  }
  return U;
}
struct edge{
  int from,to;
  float cost;
};
float cos_score(vector<float> &a,vector<float> &b){
  float bunshi = 0;
  for(int i = 0;i< a.size();i++){
    bunshi += a[i] * b[i];
  }
  return 1.0 - bunshi;
}

int main()
{
  // 整数の入力
  ui seed;
  cin >> seed;
  vector<vector<float>> D(5000,vector<float>(200,0));
  ui x = 123456789;
  ui y = 362436069;
  ui z = 521288629;
  ui w = seed;

  for (int i = 0; i < 5000; i++)
  {
    for(int j= 0;j < 200;j++){
      ui t = x ^ (x << 11);
      x = y;
      y = z;
      z = w;
      w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
      int v = (int)(w % 100000) - 50000;
      if( v >= 0){
        v = v + 1;
      }
      // cout << v << endl;
      D[i][j] = v;
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    float size = 0;
    for(int j= 0;j < 200;j++){
      size += D[i][j] * D[i][j];
    }

    for(int j= 0;j < 200;j++){
      D[i][j] /= sqrt(size);
    }
    // cout << size << endl;
  }

  vector<edge> G;
  for(int i = 0;i < 5000;i++){
    for(int j = i+1; j< 5000;j++){
      edge e;
      e.from = i;
      e.to = j;
      e.cost = cos_score(D[i],D[j]);
      G.push_back(e);
    }
  }

  UnionFind uf(5000);
  sort(G.begin(),G.end(),[](edge &a ,edge &b){return a.cost < b.cost;});
  float total_cost = 0;
  for(auto &e: G){
    if(uf.unite(e.from,e.to)){
      cout << e.from + 1 << " " << e.to + 1<< "\n";
      total_cost += e.cost;
    }
  }
  // cout << total_cost << "\n";
  cout << flush;
  return 0;
}