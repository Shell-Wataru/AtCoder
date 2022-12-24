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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

bool dfs(ll current,ll used,vector<vector<ll>> &G,vector<vector<int>> &cache){
  if (cache[current][used] != -1){
    return cache[current][used];
  }
  bool win_any = false;
  for(auto to:G[current]){
    if ( !(used & 1ll<<to)){
      win_any |= !dfs(to,used | 1ll<< to,G,cache);
    }
  }
  cache[current][used] = win_any;
  return win_any;
}
int main()
{
  ll N;
  cin >> N;
  vector<string> S(N);
  vector<vector<ll>> G(N);
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if (i == j){
        continue;
      }
      if (S[i].back() == S[j].front()){
        G[i].push_back(j);
      }
    }
  }
  vector<vector<int>> cache(N,vector<int>(1ll<<N,-1));
  bool win = false;
  for(int i = 0;i < N;i++){
    win |= !dfs(i,1ll<<i,G,cache);
  }
  if (win){
    cout << "First" << endl;
  }else{
    cout << "Second" << endl;
  }

  return 0;
}
