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

map<ll, ll> projection = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 1},
    {5, 3},
    {6, 5}};
int main()
{
  ll N;
  cin >> N;
  string S = "";
  vector<ll> counts(7);
  ll total = 0;
  while (total < N)
  {
    // cout << total << endl;
    // for (int i = 0; i < 7; i++)
    // {
    //   cout << counts[i] << ",";
    // }
    // cout << endl;
    ll target = -1;
    ll maximum = -1;
    for (int i = 0; i < 7; i++)
    {

      if (total + counts[projection[i]] + (i == 0) <= N)
      {
        if (maximum < counts[projection[i]] + (i == 0))
        {
          maximum = counts[projection[i]] + (i == 0);
          target = i;
        }
      }
    }

    total += counts[projection[target]] + (target == 0);
    if (target == 0)
    {
      S += '7';
    }
    else
    {
      S += '0' + target;
    }
    vector<ll> new_counts(7);
    for (int j = 0; j < 7; j++)
    {
      new_counts[(10 * j + target) % 7] = counts[j];
    }
    counts = new_counts;
    counts[target]++;
  }
  cout << S << endl;
  return 0;
}
