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

int main()
{
  // 整数の入力
  ll a,b,c;
  cin >> a >> b >> c;
  vector<vector<vector<double>>> DP(101,vector<vector<double>>(101,vector<double>(101,0)));
  for(int i = 99;i>=0;i--){
    for(int j = 99;j >= 0;j--){
      for(int k = 99;k >= 0;k--){
        ll total = i + j + k;
        DP[i][j][k] = (DP[i+1][j][k] + 1) * i/total + (DP[i][j+1][k] + 1) * j/total + (DP[i][j][k+1] + 1) * k/total;
      }
    }
  }
  cout << fixed << setprecision(12)<< DP[a][b][c] << endl;
  return 0;
}
