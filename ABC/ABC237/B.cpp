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
  ll N;
  cin >> N;
  deque<ll> q;
  string S;
  cin >> S;
  q.push_back(0);
  vector<pair<ll,ll>>  neighbors(N+1,{-1,-1});
  for(int i = 1;i <= N;i++){
    if (S[i-1] == 'R'){
      ll old_r = neighbors[i-1].second;
      if (old_r != -1){
        neighbors[old_r].first = i;
      }
      neighbors[i].second = old_r;
      neighbors[i].first = i-1;
      neighbors[i-1].second = i;
    }else{
      ll old_l = neighbors[i-1].first;
      if (old_l != -1){
        neighbors[old_l].second = i;
      }
      neighbors[i].first = old_l;
      neighbors[i].second = i-1;
      neighbors[i-1].first = i;
    }
  }

  // for(int i = 0;i <= N;i++){
  //   cout << i << ":" << neighbors[i].first << "," << neighbors[i].second << endl;
  // }
  ll start=-1;
  for(int i = 0;i <= N;i++){
    if (neighbors[i].first == -1){
      start = i;
      break;
    }
  }
  ll current = start;
  vector<ll> ans;
  while(current != -1){
    // cout << "!";
    ans.push_back(current);
    current = neighbors[current].second;
  }
  // cout << endl;
  for(int i = 0;i <= N;i++){
    if (i!= 0){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}