#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;


struct Edge
{
    ll from, to;
    ll w;
};

bool bellman_ford(int n, vector<Edge> &edges, vector<ll> &dists)
{
    for (int i = 0; i < n; i++)
    {
        // cout << "i" << i << endl;
        for (auto e : edges)
        {
            if (dists[e.from] + e.w < dists[e.to] )
            {
                dists[e.to] = dists[e.from] + e.w;
                if (i == n - 1)
                {
                    // cout << dists[e.to] << endl;
                    return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}


ll s_index(string s){
  ll number = 0;
  ll base = 1;
  reverse(s.begin(),s.end());
  for(size_t i = 0;i < s.size();i++){
    number += (s[i] - 'a' + 1)*base;
    base*= 27;
  }
  return number;
}
ll solve()
{
  size_t N;
  cin >> N;
  vector<vector<pair<ll,ll>>> G(27*27*27*2);
  vector<ll> costs(27*27*27,0);
  vector<Edge> edges;
  for(int i = 0;i < N;i++){
    string T;
    ll P;
    cin >> T >> P;
    reverse(T.begin(),T.end());
    ll number = 0;
    ll base = 1;
    for(int i = 0;i < T.size();i++){
      number += (T[i] - 'a' + 1)*base;
      base*= 27;
    }
    for(int i = 0;base*i+number< 27*27*27;i++){
      costs[base*i+number] += P;
    }
  }
  // cout << "!!" << endl;
  for(int i = 1;i < 27*27*27;i++){
    G[2*i].push_back({2*i+1,-costs[i]});
    edges.push_back({2*i,2*i+1,-costs[i]});
    ll to_base  = (i*27)%(27*27*27);
    for(int j =1;j < 27;j++){
      G[2*i+1].push_back({2*(to_base+j),0});
      edges.push_back({2*i+1,2*(to_base+j),0});
    }
  }
  // cout << "!!" << endl;
  ll ans = numeric_limits<ll>::max();
  for(int i = 1;i < 27;i++){
    vector<ll> dists(27*27*27*2,numeric_limits<ll>::max()/4);
    dists[2*i] = 0;
    bool found_cycle = bellman_ford(15,edges,dists);
    if (found_cycle){
      cout << "Infinity" << endl;
      return 0;
    }else{
      for(int i = 1;i < 27;i++){
        ans =min(ans,dists[2*(i)+1]);
        for(int j = 1;j < 27;j++){
          ans =min(ans,dists[2*(i+27*j)+1]);
          for(int k = 1;k < 27;k++){
            ans =min(ans,dists[2*(i+27*j+27*27*k)+1]);
          }
        }
      }
    }
  }
  cout << -ans << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
