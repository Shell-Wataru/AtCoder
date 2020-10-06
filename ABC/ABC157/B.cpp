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

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  vector<vector<ll>> A(3, vector<ll>(3, 0));
  for (int i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++)
    {
      cin >> A[i][j];
    }
  }
  ll N;
  cin >> N;
  for (size_t i = 0; i < N; i++)
  {
    ll b;
    cin >> b;
    for (int i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (A[i][j] == b)
        {
          A[i][j] = -1;
        }
      }
    }
  }

  bool is_clear = false;
  // 縦
  for (int i = 0; i < 3; i++)
  {
    bool c = true;
    for (size_t j = 0; j < 3; j++)
    {
      if (A[i][j] != -1)
      {
        c = false;
      }
    }
    if (c)
    {
      is_clear = true;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    bool c = true;
    for (size_t j = 0; j < 3; j++)
    {
      if (A[j][i] != -1)
      {
        c = false;
      }
    }
    if (c)
    {
      is_clear = true;
    }
  }

  bool cc = true;
  for (size_t j = 0; j < 3; j++)
  {
    if (A[j][j] != -1)
    {
      cc = false;
    }
  }
  if (cc)
  {
    is_clear = true;
  }

  bool ccc = true;
  for (size_t j = 0; j < 3; j++)
  {
    if (A[2 - j][j] != -1)
    {
      ccc = false;
    }
  }
  if (ccc)
  {
    is_clear = true;
  }

  if (is_clear){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}