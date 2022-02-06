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
#include <climits>
using namespace std;
using ll = long long;

void warshall_floyd(int n, vector<vector<ll>> &D)
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
}

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> Edges;
  vector<pair<ll, ll>> revEdges;
  vector<vector<ll>> G(N);
  vector<vector<ll>> revG(N);
  vector<vector<ll>> D(N, vector<ll>(N, numeric_limits<ll>::max() / 2));
  vector<vector<ll>> revD(N, vector<ll>(N, numeric_limits<ll>::max() / 2));
  for (int i = 0; i < N; i++)
  {
    D[i][i] = 0;
    revD[i][i] = 0;
  }
  for (int i = 0; i < M; i++)
  {
    ll s, t;
    cin >> s >> t;
    s--;
    t--;
    D[s][t] = 1;
    revD[t][s] = 1;
    G[s].push_back(t);
    revG[t].push_back(s);
    Edges.push_back({s, t});
    revEdges.push_back({t, s});
  }
  // cout << "!!!" << endl;
  warshall_floyd(N, D);
  warshall_floyd(N, revD);
  for (int i = 0; i < M; i++)
  {
    ll s = Edges[i].first;
    ll t = Edges[i].second;
    // cout << "s" << s << "t"  << + t << endl;
    // cout << "s" << D[0][s]<< "t"  << + revD[N-1][t] << endl;
    ll distance = numeric_limits<ll>::max();
    // for(int j = 0;j < N;j++){
    //   if (j != s && D[0][j] == D[0][s]){
    //     distance = min(distance,D[0][j] + revD[N-1][j]);
    //   }
    // }
    // cout << distance << endl;
    // for(int j = 0;j < N;j++){
    //   if (j != t && revD[N-1][j] == revD[N-1][t]){
    //     distance = min(distance,D[0][j] + revD[N-1][j]);
    //   }
    // }
    // cout << distance << endl;
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        if (D[0][j] == D[0][s] && D[0][k] == D[0][s] + 1 && !(s == j && t == k))
        {
          distance = min(distance, D[0][j] + D[k][N - 1] + 1);
        }
      }
    }
    // cout << distance << endl;

    if (distance >= numeric_limits<ll>::max() / 2)
    {
      cout << -1 << "\n";
    }
    else
    {
      cout << distance << "\n";
    }
  }
  cout << flush;
  return 0;
}