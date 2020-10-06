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

int main()
{
  ll N;
  cin >> N;
  vector<string> G(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> G[i];
  }

  ll shots = 0;
  for (size_t i = 0; i < N; i++)
  {
    ll last_white = -1;
    for (int j = 0; j < N; j++)
    {
      if (G[i][j] == '.')
      {
        last_white = j;
      }
    }
    if (last_white != -1)
    {
      shots++;
      for (size_t j = 0; j <= last_white; j++)
      {
        G[i][j] = 'o';
      }
      if (i + 1 < N)
      {
        for (size_t j = last_white; j < N; j++)
        {
          G[i + 1][j] = 'o';
        }
      }
    }
  }
  cout << shots << endl;
  return 0;
}