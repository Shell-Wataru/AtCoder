#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  cin >> n >>m;
  vector<pair<ll,ll>> edges(m);
  for(int i = 0;i < m;i++){
    scanf("%lld",&edges[i].first);
    scanf("%lld",&edges[i].second);
    if (edges[i].first < edges[i].second){
      swap(edges[i].first,edges[i].second);
    }
  }
  edges.push_back({numeric_limits<ll>::max(),numeric_limits<ll>::max()});
  sort(edges.begin(),edges.end());
  ll ans = 0;
  ll edge_index = 0;
  ll start = 1;
  for(int i = 1;i <= n;i++){
    while(edges[edge_index].first == i){
      start = max(start, edges[edge_index].second+1);
      edge_index++;
    }
    ans += i-start+1;
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}