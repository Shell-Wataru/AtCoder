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
  ll M,N;
  cin >> N >> M;
  vector<ll> A(N);
  for(int i = 0;i < N;i++ ){
    cin >> A[i];
  }
  vector<vector<ll>> DP(N+1,vector<ll>(M+1,numeric_limits<ll>::min()/2));
  DP[0][0] = 0;
  for(int i = 0;i < N;i++){
    for(int j = 0;j <= M;j++){
      DP[i+1][j] = max(DP[i+1][j],DP[i][j]);
      if (j < M){
        DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j]+ A[i] *(j+1));
      }
    }
  }
  cout << DP[N][M] << endl;
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
