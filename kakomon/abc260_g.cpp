#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> S(n);
  for(int i = 0;i < n;i++){
    cin >> S[i];
  }
  vector<vector<int>> cumulativeSumVertical(3*n+1,vector<int>(5*n+1));
  vector<vector<int>> cumulativeSumDiagonal(3*n+1,vector<int>(5*n+1));
  vector<vector<int>> cumulativeSumTotal(3*n+1,vector<int>(5*n+1));
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if (S[i][j] == 'O'){
        cumulativeSumVertical[i][j] += 1;
        cumulativeSumVertical[i+m][j] += -1;
        cumulativeSumDiagonal[i][j+2*m] += -1;
        cumulativeSumDiagonal[i+m][j] += 1;
      }
    }
  }
  for(int i = 0;i < 3*n+1;i++){
    for(int j = 0;j < 5*n+1;j++){
      if (i > 0){
        cumulativeSumVertical[i][j] += cumulativeSumVertical[i-1][j];
      }
      if (i > 0 && j+2 < 5*n+1){
        cumulativeSumDiagonal[i][j] += cumulativeSumDiagonal[i-1][j+2];
      }
    }
  }
  for(int i = 0;i < 3*n+1;i++){
    for(int j = 0;j < 5*n+1;j++){
      cumulativeSumTotal[i][j] = cumulativeSumVertical[i][j] + cumulativeSumDiagonal[i][j];
    }
  }
  // cout << "diagonal" << endl;
  // for(int i = 0;i < 5*n+1;i++){
  //   for(int j = 0;j < 5*n+1;j++){

  //     cout << cumulativeSumDiagonal[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << "vertical" << endl;
  // for(int i = 0;i < 5*n+1;i++){
  //   for(int j = 0;j < 5*n+1;j++){

  //     cout << cumulativeSumVertical[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << "total" << endl;
  // for(int i = 0;i < 5*n+1;i++){
  //   for(int j = 0;j < 5*n+1;j++){

  //     cout << cumulativeSumTotal[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << "!!" << endl;
  for(int i = 0;i < 3*n+1;i++){
    for(int j = 0;j < 5*n+1;j++){
      if (j > 0){
        cumulativeSumTotal[i][j] += cumulativeSumTotal[i][j-1];
      }
    }
  }
  // for(int i = 0;i < 5*n+1;i++){
  //   for(int j = 0;j < 5*n+1;j++){

  //     cout << cumulativeSumTotal[i][j] << ",";
  //   }
  //   cout << endl;
  // }

  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll x,y;
    cin >> x >> y;
    x--;y--;
    cout << cumulativeSumTotal[x][y] << "\n";
  }
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
