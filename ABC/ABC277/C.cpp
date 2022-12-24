#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int dfs(unordered_map<ll,vector<ll>> &G,unordered_map<ll,bool> &visited,ll current){
  visited[current] = true;
  for(auto to:G[current]){
    if (!visited.count(to)){
      dfs(G,visited,to);
    }
  }
  return 0;
}
int main()
{
  ll N;
  cin >> N;
  unordered_map<ll,vector<ll>> G;
  unordered_map<ll,bool> visited;
  for(int i = 0;i < N;i++){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(G,visited,0);
  ll ans = 0;
  for(auto p:visited){
    ans = max(ans,p.first);
  }
  cout << ans + 1 << endl;
  return 0;
}