#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;
map<vector<ll>,ll> cache;
ll answer(vector<pair<ll,ll>> &A,vector<ll> range){
    if (cache.count(range)){
        return cache[range];
    }
    ll ans = 0;
    for(auto a:A){
        if (range[0] <= a.first && a.first < range[1] && range[2] <= a.second && a.second < range[3]){
            ll v = range[1]-range[0] + range[3] - range[2]-1
                    + answer(A,{range[0],a.first,range[2],a.second})
                    + answer(A,{range[0],a.first,a.second+1,range[3]})
                    + answer(A,{a.first+1,range[1],range[2],a.second})
                    + answer(A,{a.first+1,range[1],a.second+1,range[3]});
            ans = max(ans,v);
        }
    }
    cache[range] = ans;
    return ans;
}
int solve()
{
  ll W, H;
  cin >> W >> H;
  ll N;
  cin >> N;
  vector<pair<ll,ll>> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i].first >> A[i].second;
  }
  cout << answer(A,{1,W+1,1,H+1}) << endl;
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}