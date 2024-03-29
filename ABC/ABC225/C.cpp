#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> B(N, vector<ll>(M, 0));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> B[i][j];
      B[i][j]--;
    }
  }
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (B[i][j] + 7 == B[i + 1][j])
      {
        continue;
      }
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M - 1; j++)
    {
      if (B[i][j] % 7 + 1 == B[i][j + 1] % 7)
      {
        continue;
      }
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}