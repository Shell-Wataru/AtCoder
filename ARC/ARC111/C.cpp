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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

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

void dfs(vector<vector<pair<ll,ll>>> &G,ll current_node, vector<ll> &node_colors){
    // cout <<"n:" <<current_node << endl;
    for(auto &e:G[current_node]){
        if (node_colors[e.first] == -1){
            if (node_colors[current_node] == e.second){
                vector<ll>edge_colors;
                for(auto &ee:G[e.first]){
                    edge_colors.push_back(ee.second);
                }
                sort(edge_colors.begin(),edge_colors.end());
                ll color = 1;
                for(auto &c:edge_colors){
                    if (color == c){
                        color++;
                    }else{
                        break;
                    }
                }
                node_colors[e.first] = color;
            }else{
                node_colors[e.first] = e.second;
            }
            dfs(G,e.first, node_colors);
        }
    }
}
int main()
{
  ll N , M;
  scanf("%lld",&N);
  scanf("%lld",&M);

  vector<vector<pair<ll,ll>>> G(N);
  vector<ll> node_colors(N,-1);
  UnionFind uf(N);
  for(int i = 0;i < M;i++){
      ll u,v,c;
      scanf("%lld",&u);
      scanf("%lld",&v);
      scanf("%lld",&c);
      u--;v--;
      if (uf.unite(u,v)){
        G[u].push_back({v,c});
        G[v].push_back({u,c});
      }
  }
  ll edge_node;
  for(int i = 0; i< N;i++){
      if (G[i].size() == 1){
          edge_node = i;
          break;
      }
  }
  node_colors[edge_node] = G[edge_node][0].second;
  dfs(G,edge_node,node_colors);
  for(int i = 0;i < N;i++){
      cout << node_colors[i] << "\n";
  }
  cout << flush;
  return 0;
}