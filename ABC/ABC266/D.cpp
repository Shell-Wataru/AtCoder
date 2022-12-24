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

int solve()
{
  ll N;
  cin >> N;
  vector<vector<ll>> DP(100001,vector<ll>(5,numeric_limits<ll>::min()));
  DP[0][0] = 0;
  vector<vector<ll>> snukes(N,vector<ll>(3));
  for(int i = 0;i < N;i++){
    cin >> snukes[i][0] >> snukes[i][1] >> snukes[i][2];
  }
  ll snuke_index = 0;
  for(int i = 1;i <= 100000;i++){
    for(int j = 0;j <= 4;j++){
      if (snuke_index < N && snukes[snuke_index][0] == i && snukes[snuke_index][1] == j){
        for(int k = -1;k <= 1;k++){
          ll before_j = j+k;
          if (0 <= before_j && before_j <= 4){
            DP[i][j] = max(DP[i][j],DP[i-1][before_j] + snukes[snuke_index][2]);
          }
        }
        snuke_index++;
      }else{
        for(int k = -1;k <= 1;k++){
          ll before_j = j+k;
          if (0 <= before_j && before_j <= 4){
            DP[i][j] = max(DP[i][j],DP[i-1][before_j]);
          }
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 0;i <= 4;i++){
    ans = max(ans, DP[100000][i]);
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
