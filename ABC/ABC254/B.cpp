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
  ll N;
  cin >> N;
  vector<vector<ll>> A(N,vector<ll>(N,0));
  A[0][0] = 1;
  for(int i = 0;i < N-1;i++){
    for(int j = 0;j < N-1;j++){
      A[i+1][j] += A[i][j];
      A[i+1][j+1] += A[i][j];
    }
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j <= i;j++){
      if (j != 0){
        cout << " ";
      }
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}