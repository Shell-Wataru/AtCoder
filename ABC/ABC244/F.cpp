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

int solve()
{
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> G(N);
  for (int i = 0; i < M; i++)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<vector<ll>> DP(1ll << N,  vector<ll>(N, numeric_limits<ll>::max() / 2));
  queue<vector<ll>> q;
  // DP[0][0][0] = 0;
  for (int i = 0; i < N; i++)
  {
    DP[1ll << i][i] = 1;
    q.push({1ll << i, i, 1});
  }
  while (!q.empty())
  {
    ll i = q.front()[0];
    ll j = q.front()[1];
    ll d = q.front()[2];
    q.pop();

    for (auto to : G[j])
    {
      if (d + 1 < DP[i ^ 1ll << to][to])
      {
        DP[i ^ 1ll << to][to] = d + 1;
        q.push({i ^ 1ll << to, to, d + 1});
      }
    }
  }
  ll ans = 0;
  // cout << numeric_limits<ll>::max() << endl;
  for (int i = 1; i < 1ll << N; i++)
  {
    ll current = numeric_limits<ll>::max();
    for (int j = 0; j < N; j++)
    {
      current = min(current, DP[i][j]);
    }
    // cout << i << ":" << current << endl;
    ans += current;
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // ll T;
  // cin >> T;
  // for (int i = 0; i < T; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
