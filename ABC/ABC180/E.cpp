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
using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<vector<ll>> points(N);
  for (size_t i = 0; i < N; i++)
  {
    ll x,y,z;
    cin >> x >> y >> z;
    points[i] = {x,y,z};
  }

  vector<vector<ll>> DP(1<<N,vector<ll>(N,numeric_limits<ll>::max()/2));
  DP[1][0] = 0;
  for(int i = 1;i < (1<<N);i++){
    for(int j = 0;j < N;j++){
      if (i & (1<<j)){
        // cout << "!" << endl;
        for(int k = 0;k < N;k++){
          DP[i | (1<<k)][k] = min(DP[i | (1<<k)][k],DP[i][j] + abs(points[j][0] - points[k][0]) +  abs(points[j][1] - points[k][1]) + max(0ll,points[k][2] - points[j][2]));
        }
      }
    }
  }
  cout << DP[(1<<N) - 1][0] << endl;
  return 0;
}
