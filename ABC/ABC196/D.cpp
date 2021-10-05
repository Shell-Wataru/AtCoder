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

ll solve(ll H, ll W, ll A)
{
  vector<vector<vector<vector<ll>>>> DP(H + 1, vector<vector<vector<ll>>>(W, vector<vector<ll>>(A + 1, vector<ll>(1 << W, 0))));
  DP[0][0][0][0] = 1;
  for (int i = 0; i < H; i++)
  {
    for (size_t j = 0; j < W; j++)
    {
      // cout << i << "," << j  << ":" << DP[i][j][(1<<W)-1] << endl;
      for (int a = 0; a <= A; a++)

        for (int k = 0; k < (1 << W); k++)
        {
          {
            // cout << i << "," << j  << "," << k<< ":" << DP[i][j][k] << endl;
            if ((k & 1 << j))
            {
              // おけない
              if (j + 1 < W)
              {
                DP[i][j + 1][a][k & ~(1 << j)] += DP[i][j][a][k];
              }
              else
              {
                DP[i + 1][0][a][k & ~(1 << j)] += DP[i][j][a][k];
              }
            }
            else
            {
              // 縦
              if (i + 1 < H)
              {
                if (j + 1 < W)
                {
                  DP[i][j + 1][a][k | 1 << j] += DP[i][j][a][k];
                }
                else
                {
                  DP[i + 1][0][a][k | 1 << j] += DP[i][j][a][k];
                }
              }
              // 横
              if (j + 1 < W && !(k & 1 << (j + 1)))
              {
                if (j + 1 < W)
                {
                  DP[i][j + 1][a][k | 1 << (j + 1)] += DP[i][j][a][k];
                }
                else
                {
                  DP[i + 1][0][a][k | 1 << (j + 1)] += DP[i][j][a][k];
                }
              }

              // 一升
              if (a + 1 <= A)
              {
                if (j + 1 < W)
                {
                  DP[i][j + 1][a + 1][k] += DP[i][j][a][k];
                }
                else
                {
                  DP[i + 1][0][a + 1][k] += DP[i][j][a][k];
                }
              }
            }
          }
        }
    }
  }
  // for(int i = 0;i <= A;i++){
  //   cout << DP[H][0][i][0] << endl;
  // }
  return DP[H][0][A][0];
}
int main()
{
  // 整数の入力
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  ll ans = solve(H, W, B);
  cout << ans << endl;
  return 0;
}
