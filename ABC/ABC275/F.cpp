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

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<ll> a(N);
  for(int i = 0;i < N;i++){
    cin >> a[i];
  }
  vector<vector<vector<ll>>> DP(N+1,vector<vector<ll>>(2,vector<ll>(M+1,numeric_limits<ll>::max()/2)));
  DP[0][1][0] = 0;

  for(int i = 0;i < N;i++){
    for(int j = 0;a[i]+j <= M;j++){
      DP[i+1][1][a[i]+j] = min(DP[i+1][1][a[i]+j],DP[i][0][j]);
      DP[i+1][1][a[i]+j] = min(DP[i+1][1][a[i]+j],DP[i][1][j]);
    }
    for(int j = 0;j <= M;j++){
      DP[i+1][0][j] = min(DP[i+1][0][j],DP[i][0][j]);
      DP[i+1][0][j] = min(DP[i+1][0][j],DP[i][1][j]+1);
    }
  }
  for(int i = 1;i <= M;i++){
    if (min(DP[N][0][i],DP[N][1][i]) == numeric_limits<ll>::max()/2){
      cout << -1 << endl;
    }else{
      cout << min(DP[N][0][i],DP[N][1][i]) << endl;
    }
  }
  return 0;
}
