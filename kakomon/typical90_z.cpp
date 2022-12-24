#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int dfs(vector<vector<ll>> &G,ll current,ll parent,vector<ll> &depth,ll d){
    depth[current] = d;
    for(auto to:G[current]){
        if (to != parent){
            dfs(G,to,current,depth,d+1);
        }
    }
    return 0;
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> G(n);
  for(int i = 0;i < n-1;i++){
      ll a,b;
      cin >> a >> b;
      a--;b--;
      G[a].push_back(b);
      G[b].push_back(a);
  }
  vector<ll> depth(n);
  dfs(G,0,-1,depth,0);
  ll odd_count = 0;
  ll even_count = 0;
  for(auto d:depth){
      if (d%2 == 0){
          even_count++;
      }else{
          odd_count++;
      }
  }
vector<ll> answers;
  if (even_count >= odd_count){

      for(int i = 0;i < n;i++){
          if (depth[i] % 2 == 0){
              answers.push_back(i+1);
          }
      }
  }else{
      for(int i = 0;i < n;i++){
          if (depth[i] % 2 == 1){
              answers.push_back(i+1);
          }
      }
  }
  for(int i = 0;i < n/2;i++){
      if (i!= 0){
          cout << " ";
      }
      cout << answers[i];
  }
  cout << "\n";
  return 0;
}

int main()
{
  // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}
