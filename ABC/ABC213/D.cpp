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

int dfs(vector<vector<ll>> &G,ll current,ll parent, vector<ll> &answer){
  answer.push_back(current);
  for(auto to:G[current]){
    if (to != parent){
      dfs(G,to,current,answer);
      answer.push_back(current);
    }
  }
  return 0;
}
int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<vector<ll>> G(N);
  for (size_t i = 0; i < N-1; i++)
  {
    ll a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 0;i < N;i++){
    sort(G[i].begin(),G[i].end());
  }
  vector<ll> answer;
  dfs(G,0,-1,answer);
  for(int i = 0;i < answer.size();i++){
    if (i != 0){
      cout << " ";
    }
    cout << answer[i] + 1;
  }
  cout << endl;
  return 0;
}
