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
  vector<string> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  for(int i = 0;i < N;i++){
    for(int j = i+1;j<N;j++){
      if (A[i][j] == 'W'){
        if (A[j][i] != 'L'){
          cout << "incorrect" << endl;
          return 0;
        }
      }else if (A[i][j] == 'L'){
        if (A[j][i] != 'W'){
          cout << "incorrect" << endl;
          return 0;
        }
      }else{
        if (A[j][i] != 'D'){
          cout << "incorrect" << endl;
          return 0;
        }
      }
    }
  }
  cout << "correct" << endl;
  return 0;
}