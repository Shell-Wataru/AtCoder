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
using namespace std;
using ll = long long;

struct node{
  ll x,y,d;
};
int main()
{
  // 整数の入力
  ll H,W;
  cin >> H >> W;
  vector<string> G(H);
  vector<vector<ll>> D(H,vector<ll>(W,numeric_limits<ll>::max()));
  pair<ll,ll> start,goal;
  vector<vector<pair<ll,ll>>>  warps(26);
  vector<bool>  warped(26);

  for(int i = 0;i < H;i++){
    cin >> G[i];
  }
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      if (G[i][j] == 'S'){
        start = {i,j};
      }else if (G[i][j] == 'G'){
        goal = {i,j};
      }else if(G[i][j] == '.'){
      }else if(G[i][j] == '#'){
      }else{
        warps[G[i][j]-'a'].emplace_back(i,j);
      }
    }
  }
  queue<node> q;
  q.push({start.first,start.second,0});
  vector<pair<ll,ll>>directions = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
  };
  // cout << "!!!" << endl;
  while(!q.empty()){
    node current = q.front();
    q.pop();
    if (D[current.x][current.y] != numeric_limits<ll>::max()){
      continue;
    }
    // cout << current.x << ","<< current.y << endl;
    D[current.x][current.y] = current.d;
    if (G[current.x][current.y] == 'G'){
      break;
    }
    for(auto &d:directions){
      ll x = current.x + d.first;
      ll y = current.y + d.second;
      if(0 <= x && x < H && 0 <= y && y < W){
        if(G[x][y] != '#' && D[x][y] == numeric_limits<ll>::max()){
          q.push({x,y,current.d+1});
        }
      }
    }

    // cout << warps[G[current.x][current.y]].size() << endl;
    ll char_index = G[current.x][current.y] - 'a';
    if (0 <= char_index && char_index < 26 && !warped[char_index]){
      warped[char_index] = true;
      // cout << "aa" << endl;
      for(auto &to:warps[char_index]){
        if(D[to.first][to.second] == numeric_limits<ll>::max()){
          q.push({to.first,to.second,current.d+1});
        }
      }
      // cout << "aa" << endl;
    }
  }

  // cout << "!!!" << endl;
  if(D[goal.first][goal.second] == numeric_limits<ll>::max()){
    cout << -1 << endl;
  }else{
    cout << D[goal.first][goal.second] << endl;
  }
  return 0;
}
