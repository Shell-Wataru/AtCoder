#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

ll reverse(ll n, ll modulo)
{
  ll x, y;
  extGCD(n, modulo, x, y);
  return (x + ((abs(x / modulo) + 1) * modulo)) % modulo;
}

ll my_distance(vector<ll> &D, int i, int j)
{
  ll small = min(i, j);
  ll big = max(i, j);
  if (small == 0)
  {
    return 0;
  }
  else
  {
    // cout << big << ":" <<D[big] << " " << small << ":" << D[small] << endl;
    return D[big] - D[small];
  }
}
int main()
{
  // 整数の入力
  ll N, M, K;
  cin >> N >> M >> K;
  vector<string> answer(N);
  vector<ll> D(N + 1, 0);
  for (int i = 1; i < N; i++)
  {
    ll d;
    cin >> d;
    D[i + 1] = D[i] + d;
    // cout << D[i+1] << endl;
  }
  vector<vector<vector<vector<ll>>>> DP(N + 1, vector<vector<vector<ll>>>(K + 1, vector<vector<ll>>(N + 1, vector<ll>(M, 0))));
  DP[0][0][0][0] = 1;
  for (int h = 1; h <= N; h++)
  {
    for (int i = 1; i <= N; i++)
    {
      cout << i << "=====" << endl;
      for (int j = 0; j <= K; j++)
      {
        for (int k = 0; k <= N; k++)
        {
          for (int l = 0; l < M; l++)
          {
            ll current = DP[i - 1][j][k][l];
            DP[i][j][k][l] += current;
            if (j < K)
            {
              ll ki = my_distance(D, k, i);
              DP[i][j + 1][i][(l + ki) % M] += current;
            }
          }
        }
      }
    }
  }
  cout << "aa" << endl;
  ll total = 0;
  for (int k = 0; k <= N; k++)
  {
    cout << k << ":" << DP[N][K][k][0] << endl;
    total += DP[N][K][k][0];
  }
  cout << total << endl;
  return 0;
}