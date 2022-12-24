#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll char_index(char c){
  if (c  < 'a'){
    return c - 'A';
  }else{
    return c - 'a' + 26;
  }
}

char char_from_index(ll index){
  if (index < 26){
    return 'A' + index;
  }else{
    return 'a' + index - 26;
  }
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<string> S(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> S[i];
  }
  vector<vector<vector<ll>>> SIndices(n,vector<vector<ll>>(52));
  for(int i = 0;i < n;i++){
    for(int j = 0;j < S[i].size();j++){
      SIndices[i][char_index(S[i][j])].push_back(j);
    }
  }
  map<vector<ll>,string> answers;
  answers[vector<ll>(n,-1)] = "";
  for(int i = 0;i < 104;i++){
    for(auto p:answers){
      if (p.second.size() != i){
        continue;
      }
      for(int j =0;j < 52;j++){
        vector<ll> next(n);
        bool made = true;
        for(int k = 0;k < n;k++){
          bool found = false;
          for(auto l:SIndices[k][j]){
            if (p.first[k] < l){
              next[k] = l;
              found = true;
              break;
            }
          }
          if (!found){
            made = false;
            break;
          }
        }
        if (made){
          answers[next] = p.second + char_from_index(j);
        }
      }
    }
  }
  string answer = "";
  for(auto p:answers){
    if (p.second.size() > answer.size()){
      answer = p.second;
    }
  }
  cout << answer.size() << "\n";
  cout << answer << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}
