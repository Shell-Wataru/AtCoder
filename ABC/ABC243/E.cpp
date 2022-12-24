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

void warshall_floyd(int n, vector<vector<ll>> &d)
{
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
}

int solve(){
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> Edges(M);
  vector<bool> removed(M,false);
  vector<vector<ll>> G(N,vector<ll>(N,numeric_limits<ll>::max()/2));
  vector<vector<ll>> EdgeNumbers(N,vector<ll>(N,-1));
  vector<vector<ll>> D(N,vector<ll>(N,numeric_limits<ll>::max()/2));
  for(int i = 0; i < M;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    Edges[i] = {a,b,c};
    G[a][b] = c;
    G[b][a] = c;
    EdgeNumbers[a][b] = i;
    EdgeNumbers[b][a] = i;
    D[a][b] = c;
    D[b][a] = c;
  }
  ll ans= 0;
  for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (G[i][j] != numeric_limits<ll>::max()/2 && D[i][k] + D[k][j] <=  G[i][j]){
                  removed[EdgeNumbers[i][j]] = true;
                }
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    for(auto r:removed){
      if (r){
        ans++;
      }
    }
  cout << ans << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
    solve();
  // }
  cout << flush;
  return 0;
}
