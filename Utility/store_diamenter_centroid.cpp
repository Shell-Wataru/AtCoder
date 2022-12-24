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
#include <climits>
using namespace std;
using ll = long long;

pair<ll, ll> dfs2(vector<vector<ll>> &g, vector<ll> &parents, ll current, ll parent)
{
  pair<ll, ll> ans = {0, current};
  parents[current] = parent;
  for (auto to : g[current])
  {
    if (to != parent)
    {
      auto p = dfs2(g, parents, to, current);
      if (p.first + 1 > ans.first)
      {
        ans = {p.first + 1, p.second};
      }
    }
  }
  return ans;
}

vector<ll> diameter_centroid(vector<vector<ll>> &G)
{
  vector<ll> parents(G.size());
  auto p1 = dfs2(G, parents, 0, -1);
  auto p2 = dfs2(G, parents, p1.second, -1);
  ll current = p2.second;
  vector<ll> path;
  while (current != -1)
  {
    path.push_back(current);
    current = parents[current];
  }
  if (path.size() % 2 == 1)
  {
    return {path[path.size() / 2]};
  }
  else
  {
    return {path[path.size() / 2], path[path.size() / 2 - 1]};
  }
}

int main(){
    vector<vector<ll>> G = {
        {1},
        {0,2},
        {1,3},
        {2}
    };
    vector<ll> centroids = diameter_centroid(G);
    for(auto c:centroids){
        cout << c << ",";
    }
    cout << endl;
    return 0;
}