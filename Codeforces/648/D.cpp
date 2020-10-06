#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int dfs(vector<string> &G, vector<vector<bool>> &CanMove,int x,int y){
  vector<pair<ll,ll>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
  vector<pair<ll,ll>> nexts;
  for(auto d:directions){
    ll next_x = x +d.first;
    ll next_y = y +d.second;
    if (0 <= next_x && next_x < G.size() && 0 <= next_y && next_y < G[0].size()){
      if (CanMove[next_x][next_y] || G[next_x][next_y] == '#'){
        continue;
      }else if(G[next_x][next_y] == 'B'){
        G[x][y] = '#';
        nexts.clear();
        break;
      }else{
        nexts.push_back({next_x,next_y});
      }
    }
  }
  if (G[x][y] != '#'){
    CanMove[x][y] = true;
    for(auto n:nexts){
      dfs(G,CanMove,n.first,n.second);
    }
  }else{
    CanMove[x][y] = false;
  }
  return 0;
}
int solve()
{
  ll n, m;
  cin >> n >> m;
  vector<string> G(n);
  vector<vector<bool>> CanMove(n,vector<bool>(m,false));

  for(int i = 0;i < n;i++){
    cin >> G[i];
  }
  ll good_count = 0;
  for(int i = 0 ;i < n;i++){
    for(int j = 0;j < m;j++){
      if (G[i][j] == 'G'){
        good_count++;
      }
    }
  }
  dfs(G,CanMove,n-1,m-1);
  ll solved_good_count = 0;
  for(int i = 0 ;i < n;i++){
    for(int j = 0;j < m;j++){
      if (G[i][j] == 'G' && CanMove[i][j]){
        solved_good_count++;
      }
    }
  }
  if (solved_good_count == good_count){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  // cout << flush;
  return 0;
}