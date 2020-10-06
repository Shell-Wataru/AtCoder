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
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;


const long long BASE_NUM = 1000000007;

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

void print(vector<vector<ll>> &G){
    for(int i = 0;i < G.size();i++){
    for(int j = 0;j< G.size();j++){
      cout << G[i][j] << ",";
    }
    cout << endl;
  }
}
int main()
{
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> G(N,vector<ll>(N,BASE_NUM));
  for(int i = 0; i < M;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a][b] = c;
    G[b][a] = c;
  }

  warshall_floyd(N,G);
  // print(G);
  ll K;
  cin >> K;
  for(int i = 0;i < K;i++){
    ll x,y,z;
    cin >> x >> y >> z;
    x--;
    y--;
    G[x][y] = min(G[x][y],z);
    G[y][x] = min(G[y][x],z);
    for(int j = 0;j < N;j++){
      G[x][j] = min(G[x][j], G[x][y] + G[y][j]);
      G[j][x] = min(G[j][x], G[j][y] + G[y][x]);
      G[y][j] = min(G[y][j], G[y][x] + G[x][j]);
      G[j][y] = min(G[j][y], G[j][x] + G[x][y]);

    }
    for(int j = 0;j < N;j++){
      for(int k = j + 1;k < N;k++){
        G[j][k] = min(G[j][k], G[j][x] + G[x][y] + G[y][k]);
        G[j][k] = min(G[j][k], G[j][y] + G[y][x] + G[x][k]);
        G[k][j]= G[j][k];
      }
    }
    // cout << "==" << endl;
    // print(G);
    ll ans = 0;
    for(int j = 0;j < N;j++){
      for(int k = j+1;k < N;k++){
        ans += G[j][k];
      }
    }
    cout << ans << endl;
  }
  return 0;
}