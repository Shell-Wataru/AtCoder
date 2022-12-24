#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<pair<ll,ll>> moves;
  for(int i = 0;i <= 400;i++){
    for(int j = 0;j <= 400;j++){
      if (i*i + j*j == M){
        moves.push_back({i,j});
        moves.push_back({-i,j});
        moves.push_back({i,-j});
        moves.push_back({-i,-j});
      }
    }
  }
  vector<vector<ll>> mind(N,vector<ll>(N,numeric_limits<ll>::max()));
  queue<vector<ll>> q;
  q.push({0,0,0});
  while(!q.empty()){
    auto v = q.front();
    q.pop();
    ll d = v[0];
    ll x = v[1];
    ll y = v[2];
    if (d < mind[x][y]){
      mind[x][y] = d;
      for(auto p:moves){
        ll next_x = x + p.first ;
        ll next_y = y + p.second;
        if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N){
          q.push({d+1,next_x,next_y});
        }
      }
    }
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if (j != 0){
        cout << " ";
      }
      if (mind[i][j] == numeric_limits<ll>::max()){
        cout << -1;
      }else{
      cout << mind[i][j];

      }
    }
    cout << endl;
  }
  return 0;
}