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
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> A[i][j];
    }
  }
  bool is_ok = true;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      for (int k = i; k < H; k++)
      {
        for (int l = j; l < W; l++)
        {
          if (A[i][j] + A[k][l] > A[i][l] + A[k][j])
          {
            is_ok = false;
            break;
          }
        }
      }
    }
  }
  if (is_ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}