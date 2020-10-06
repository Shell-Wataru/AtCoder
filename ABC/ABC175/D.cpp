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

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll H,W;
  cin >> H >> W;
  vector<vector<ll>> D(H,vector<ll>(W,numeric_limits<ll>::max()));
  vector<string> G(H);

  ll Ch,Cw,Dh,Dw;
  cin >> Ch >> Cw >> Dh >> Dw;
  Ch--;
  Cw--;
  Dh--;
  Dw--;
  for (size_t i = 0; i < H; i++)
  {
    cin >> G[i];
  }
  priority_queue<pair<ll,pair<ll,ll>> ,vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>> > q;
  q.push({0,{Ch,Cw}});
  vector<pair<ll,ll>> directions ={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
  };
  while(!q.empty()){
    auto p = q.top();
    q.pop();
    ll d = p.first;
    ll x = p.second.first;
    ll y = p.second.second;
    // cout << x << "," << y << ":" << d << endl;
    if (d>= D[x][y]){
      continue;
    }else{
      D[x][y] = d;
      for(int i = 0;i < 4;i++){
        ll new_x = x + directions[i].first;
        ll new_y = y + directions[i].second;
        if (0 <= new_x && new_x < H && 0 <= new_y && new_y < W){
          if (G[new_x][new_y] == '.'){
            q.push({d,{new_x,new_y}});
          }
        }
      }
      for(int i = -2;i <= 2;i++){
        for(int j = -2;j <= 2;j++){
          ll new_x = x + i;
          ll new_y = y + j;
          if (0 <= new_x && new_x < H && 0 <= new_y && new_y < W){
            if (G[new_x][new_y] == '.'){
              q.push({d+1,{new_x,new_y}});
            }
          }
        }
      }
    }
  }
  if (D[Dh][Dw] == numeric_limits<ll>::max()){
    cout << -1 << endl;
  }else{
    cout << D[Dh][Dw] << endl;
  }
 return 0;
}
