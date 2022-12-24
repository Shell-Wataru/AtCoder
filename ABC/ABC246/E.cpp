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

int solve()
{
  ll N;
  cin >> N;
  ll Ax,Ay;
  ll Bx,By;
  cin >> Ax >> Ay;
  cin >> Bx >> By;
  Ax--;
  Bx--;
  Ay--;
  By--;
  vector<string> G(N);
  vector<vector<ll>> D(N,vector<ll>(N,numeric_limits<ll>::max()));
  for(int i = 0;i < N;i++){
    cin >> G[i];
  }
  queue<vector<ll>> q;
  q.push({Ax,Ay,0});
  vector<pair<ll,ll>> directions = {
    {1,1},
    {-1,1},
    {1,-1},
    {-1,-1}
  };
  D[Ax][Ay] = 0;
  while(!q.empty()){
    ll x = q.front()[0];
    ll y = q.front()[1];
    ll d = q.front()[2];
    q.pop();
    for(auto dir:directions){
      ll walk = 1;
      while(0 <= x + walk * dir.first && x + walk * dir.first < N &&
            0 <= y + walk * dir.second && y + walk * dir.second < N &&
            G[x + walk * dir.first][y + walk * dir.second] != '#' &&
            D[x + walk * dir.first][y + walk * dir.second] >= d+1
      ){
        D[x + walk * dir.first][y + walk * dir.second] = d+1;
        q.push({x + walk * dir.first,y + walk * dir.second,d+1});
        walk++;
      }
    }
  }
  if (D[Bx][By] == numeric_limits<ll>::max()){
    cout << -1 << endl;
  }else{
    cout << D[Bx][By] << endl;
  }
  // for(int i = 0;i < N;i++){
  //   for(int j = 0;j < N;j++){
  //     if (D[i][j] == numeric_limits<ll>::max()){
  //       cout << '#';
  //     }else{
  //       cout << D[i][j];
  //     }
  //   }
  //   cout << endl;
  // }
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
