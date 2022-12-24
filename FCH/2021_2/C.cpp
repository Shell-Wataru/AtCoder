#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
using ll = long long;

ll dfs1(vector<vector<pair<ll,ll>>> &G,vector<vector<ll>> &DP1,ll current,ll parent){
  DP1[current][21] = 1;
  for(auto to: G[current]){
    if (to.first != parent){
      dfs1(G,DP1,to.first,current);
      vector<ll> current_gte_count(22,0);
      vector<ll> to_gte_count(22,0);
      vector<ll> old_current_count(DP1[current]);
      for(int i = 21; i>= 0;i--){
        current_gte_count[i] += DP1[current][i];
        to_gte_count[i] += DP1[to.first][i];
        if (i+1 < 22){
          current_gte_count[i] += current_gte_count[i+1];
          to_gte_count[i] += to_gte_count[i];
        }
      }
      for(ll i = 0;i < 21;i++){
        DP1[current][min(to.second,i)] += DP1[to.first][i] * current_gte_count[i+1];
      }
      for(ll i = 0;i < 21;i++){
        DP1[current][min(to.second,i)] += old_current_count[i] * to_gte_count[i+1];
      }
      for(ll i = 0;i < 22;i++){
        DP1[current][min(to.second,i)] += old_current_count[i] * DP1[to.first][i];
      }
    }
  }
}
string solve()
{
    ll N;
    cin >> N;
    vector<vector<pair<ll,ll>>> G(N);
    vector<vector<ll>> DP1(N,vector<ll>(22,0));
    for(int i = 0;i < N;i++){
      ll a,b,c;
      cin >> a >> b >> c;
      a--;
      b--;
      G[a].push_back({b,c});
      G[b].push_back({a,c});
    }
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}