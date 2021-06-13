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
  ll N;
  cin >> N;
  vector<ll> fibonacchi(91, 1);
  for (int i = 2; i <= 90; i++)
  {
    fibonacchi[i] = fibonacchi[i - 1] + fibonacchi[i - 2];
    // cout << i << ":" << fibonacchi[i] << endl;
  }
  vector<ll> uses(91, 0);
  while (N > 0)
  {
    for (int i = 90; i >= 0; i -= 2)
    {
      if (fibonacchi[i] <= N)
      {
        N -= fibonacchi[i];
        uses[i]++;
        break;
      }
    }
  }
  // for (int i = 0; i <= 90; i++)
  // {
  //   cout << i << ":" << uses[i] << endl;
  // }
  vector<ll> operations;
  ll last_ope = 0;
  for (int i = 0; i <= 90; i++)
  {
    if (uses[i] > 0)
    {
      for(int k = 0;k < uses[i];k++){
        for (int j = last_ope; j < i; j++)
        {
          if (j % 2 == 0)
          {
            operations.push_back(3);
          }
          else
          {
            operations.push_back(4);
          }
        }
        operations.push_back(1);
        last_ope = i;
      }
    }
  }
  reverse(operations.begin(), operations.end());
  cout << operations.size() << endl;
  ll x = 0;
  ll y = 0;
  for (auto o : operations)
  {
    cout << o << endl;
    if (o == 1)
    {
      x = x + 1;
    }
    else if (o == 2)
    {
      y = y + 1;
    }
    else if (o == 3)
    {
      x = x + y;
    }
    else if (o == 4)
    {
      y = x + y;
    }
  }
  // cout << "ans" << x << endl;
  return 0;
}
