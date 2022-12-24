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

ll dfs(ll current,ll parent,vector<vector<ll>> &G,vector<ll> &C){
  ll child_max = 0;
  for(auto to: G[current]){
    if (to != parent){
      child_max = max(child_max,dfs(to,current,G,C));
    }
  }
  return C[current] + child_max;
}

string solve()
{
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    vector<ll> C(N);
    for(int i = 0;i < N;i++){
      cin >> C[i];
    }
    for(int i = 0;i < N-1;i++){
      ll u,v;
      cin >> u >> v;
      u--;
      v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    if (G[0].size() == 0){
      return to_string(C[0]);
    }else if (G[0].size() == 1){
      return to_string(C[0] + dfs(G[0][0],0,G,C));
    }else{
      vector<ll> childs;
      for(auto to:G[0]){
        childs.push_back(dfs(to,0,G,C));
      }
      sort(childs.rbegin(),childs.rend());
      return to_string(C[0] + childs[0] + childs[1]);
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