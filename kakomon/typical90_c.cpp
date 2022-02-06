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

using namespace std;
using ll = long long;

pair<ll, ll> dfs2(vector<vector<ll>> &g, ll current, ll parent)
{
  pair<ll, ll> ans = {0, current};
  for (auto to : g[current])
  {
    if (to != parent)
    {
      auto p = dfs2(g, to, current);
      if (p.first + 1 > ans.first)
      {
        ans = {p.first + 1, p.second};
      }
    }
  }
  return ans;
}

int main()
{
    // cout << primes.size();
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for(int i = 0;i < N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto p = dfs2(G,0,-1);
    auto q = dfs2(G,p.second,-1);
    cout << q.first + 1 << endl;
    return 0;
}