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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;
const vector<pair<ll,ll>> directions = {
  {0,1},
  {1,0},
  {0,-1},
  {-1,0}
};

vector<ll> next_data(map<pair<ll,ll>,vector<ll>> &neighbors,pair<ll,ll> &current,ll direction, pair<ll,ll> from){
  vector<ll> data(4);
  for(int i = 0;i < 4;i++){
    if (i == (direction + 2) % 4){
      data[i] = neighbors[from][i];
    }else{
      pair<ll,ll> neighbor = {current.first + directions[i].first,current.second + directions[i].second};
      if(neighbors.find(neighbor) == neighbors.end()){
        if (i % 2 == 0){
          data[i] = neighbor.second;
        }else{
          data[i] = neighbor.first;
        }
      }else{
        data[i] = neighbors[neighbor][i];
      }
    }
  }
  return data;
}

pair<ll,ll> dfs(map<pair<ll,ll>,vector<ll>> &neighbors,pair<ll,ll> current,ll direction,pair<ll,ll> from){
  if (neighbors.find(current) == neighbors.end()){
    neighbors[current] = next_data(neighbors,current, direction,from);
    return current;
  }else{
    neighbors[current] = next_data(neighbors,current, direction,from);
    if (direction % 2 == 0){
      pair<ll,ll> result = dfs(neighbors,{current.first,neighbors[current][direction]},direction,from);
      neighbors[current] = next_data(neighbors,current, (direction + 2) % 4,result);
      return result;
    }else{
      pair<ll,ll> result =dfs(neighbors,{neighbors[current][direction],current.second},direction,from);
      neighbors[current] = next_data(neighbors,current, (direction + 2) % 4,result);
      return result;
    }
  }
}
int main()
{
  ll K;
  cin >> K;
  string S;
  cin >> S;
  map<pair<ll,ll>,vector<ll>> neighbors;
  pair<ll,ll> current = {0,0};
  neighbors[current] = {1,1,-1,-1};
  for(int i = 0;i < K;i++){
    // cout << current.first << " " << current.second << endl;
    // cout << neighbors[current][0] <<","<< neighbors[current][1] <<","<< neighbors[current][2] << "," << neighbors[current][3] << endl;
    if (S[i] == 'L'){
      current = dfs(neighbors,current,3,current);
    }else if(S[i] == 'R'){
      current = dfs(neighbors,current,1,current);
    }else if (S[i] == 'U'){
      current = dfs(neighbors,current,0,current);
    }else if (S[i] == 'D'){
      current = dfs(neighbors,current,2,current);
    }
  }
  cout << current.first << " " << current.second << endl;
  return 0;
}