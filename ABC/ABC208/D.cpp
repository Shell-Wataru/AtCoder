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

vector<vector<ll>> warshall_floyd(int n, vector<vector<ll>> &G)
{
  vector<vector<ll>> d = G;
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}

int main()
{
  // 整数の入力
  ll N, M;
  cin >> N >> M;
  // vector<vector<ll>> G(N,vector<ll>(N,numeric_limits<ll>::max()/2));
  vector<vector<ll>> D(N, vector<ll>(N, numeric_limits<ll>::max() / 2));
  for (int i = 0; i < N; i++)
  {
    // G[i][i] = 0;
    D[i][i] = 0;
  }
  for (int i = 0; i < M; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    D[a][b] = c;
  }
  ll ans = 0;
  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (D[i][j] != numeric_limits<ll>::max() / 2)
        {
          ans += D[i][j];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
