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
  ll N, X;
  cin >> N >> X ;
  vector<bool> can(X + 1, false);
  can[0] = true;
  for (int i = 0; i < N; i++)
  {
    ll a,b;
    cin  >> a >> b;
    vector<bool> next_can(X + 1, false);
    for (int i = 0; i < X; i++)
    {
      if (can[i])
      {
        if (i + a <= X)
        {
          next_can[i + a] = true;
        }
        if (i + b <= X)
        {
          next_can[i + b] = true;
        }
      }
    }
    can = next_can;
  }
  if (can[X])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}