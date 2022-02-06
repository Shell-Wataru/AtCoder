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
  ll H, W, K;
  cin >> H >> W >> K;
  vector<vector<ll>> A(H, vector<ll>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> A[i][j];
    }
  }
  vector<vector<vector<ll>>> DP(H, vector<vector<ll>>(W, vector<ll>(K + 1,numeric_limits<ll>::max()/2)));
  DP[0][0][0] = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      for (int k = K; k >= 0; k--)
      {

        if (i > 0)
        {
          DP[i][j][k] = min(DP[i][j][k], DP[i - 1][j][k]);
        }
        if (j > 0)
        {
          DP[i][j][k] = min(DP[i][j][k], DP[i][j - 1][k]);
        }
        if (k < K){
          DP[i][j][k+1]  = min(DP[i][j][k+1],DP[i][j][k]);
        }
        DP[i][j][k] += A[i][j];
      }
    }
  }
  cout << DP[H-1][W-1][0] << endl;
  cout << DP[H-1][W-1][1] << endl;
  cout << DP[H-1][W-1][K] << endl;

  return 0;
}
