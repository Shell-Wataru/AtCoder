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
  ll N;
  vector<string> G(9);
  for (int i = 0; i < 9; i++)
  {
    cin >> G[i];
  }
  ll ans = 0;
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      for (int k = 1; k < 9; k++)
      {
        for (int l = 0; l < 9; l++)
        {
          if (0 <= i + k && i + k < 9 &&
              0 <= i + k + l && i + k + l < 9 &&
              0 <= i + l && i + l < 9 &&
              0 <= j + l && j + l < 9 &&
              0 <= j + l - k && j + l - k < 9 &&
              0 <= j - k && j - k < 9 &&
              G[i][j] == '#' && G[i + k][j + l] == '#' && G[i + k + l][j + l - k] == '#' && G[i + l][j - k] == '#')
          {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}