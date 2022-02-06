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
  ll N, X, Y;
  cin >> N >> X >> Y;
  vector<pair<ll, ll>> D(N);
  for(int i = 0;i < N;i++){
    cin >> D[i].first >> D[i].second;
  }
  vector<vector<ll>> DP(X+1, vector<ll>(Y+1, numeric_limits<ll>::max() / 2));
  DP[0][0] = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = X; j >= 0; j--)
    {
      for (int k = Y; k >= 0; k--)
      {
        DP[min(j + D[i].first,X)][min(k + D[i].second,Y)] = min(DP[min(j + D[i].first,X)][min(k + D[i].second,Y)], DP[j][k] + 1);
      }
    }
  }
  // for(int i = 0;i < 10;i++){
  //   for(int j = 0;j < 10;j++){
  //     if (DP[i][j] > 1000){
  //       cout << -1 << ",";
  //     }else{
  //       cout << DP[i][j] << ",";
  //     }
  //   }
  //   cout << endl;
  // }
  ll min_bento = DP[X][Y];
  if (min_bento == numeric_limits<ll>::max() / 2)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << min_bento << endl;
  }
  return 0;
}
