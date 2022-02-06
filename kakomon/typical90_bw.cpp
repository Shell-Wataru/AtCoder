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
#include <stack>

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<vector<ll>> A(2*N,vector<ll>(2*N,0));
  for(int i = 0;i < 2*N;i++){
    for(int j = i+1;j < 2*N;j++){
      cin >> A[i][j];
    }
  }
  // cout << "!!" << endl;
  vector<vector<ll>> answers(1ll<<(2*N));
  answers[0].push_back(0);
  for(int i = 0;i < 1ll<<(2*N);i++){
    if(__builtin_popcountll(i) % 2 == 1){
      continue;
    }
    sort(answers[i].begin(),answers[i].end());
    auto result = unique(answers[i].begin(),answers[i].end());
    answers[i].erase(result,answers[i].end());
    for(int j = 0;j < 2*N;j++){
      if (i & 1ll<<j){
        continue;
      }
      for(int k = j+1;k < 2*N;k++){
        if (i & 1ll<<k){
          continue;
        }
        for(auto v:answers[i]){
          answers[i | 1ll<<j | 1ll<<k].push_back(v ^ A[j][k]);
        }
      }
      break;
    }
  }
  ll ans = 0;
  // cout << answers[(1ll<<(2*N))-1].size() << endl;
  for(auto v:answers[(1ll<<(2*N))-1]){
    ans = max(ans,v);
  }
  cout << ans << endl;
  return 0;
}
