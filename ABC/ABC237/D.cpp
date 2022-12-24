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
#include <stack>

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
  // cout << "!!" << endl;
  for (int j = 0; j < W; j++)
  {
    for (int i = 0; i < H; i++)
    {
      if (i != 0)
      {
        cout << " ";
      }
      cout << A[i][j];
    }
    cout << endl;
  }
  // cout << "!!" << endl;
  return 0;
}
