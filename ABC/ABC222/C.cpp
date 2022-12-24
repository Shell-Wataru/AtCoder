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
  vector<string> hands(2 * N);
  for (int i = 0; i < 2 * N; i++)
  {
    cin >> hands[i];
  }
  vector<pair<ll, ll>> results(2*N);
  for (int i = 0; i < 2 * N; i++)
  {
    results[i] = {0, i};
  }
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      char first_hand = hands[results[2 * j].second][i];
      char second_hand = hands[results[2 * j + 1].second][i];
      if (first_hand == 'G' && second_hand == 'C')
      {
        results[2 * j].first++;
      }
      else if (first_hand == 'C' && second_hand == 'P')
      {
        results[2 * j].first++;
      }
      else if (first_hand == 'P' && second_hand == 'G')
      {
        results[2 * j].first++;
      }
      else if (first_hand == 'C' && second_hand == 'G')
      {
        results[2 * j + 1].first++;
      }
      else if (first_hand == 'P' && second_hand == 'C')
      {
        results[2 * j + 1].first++;
      }
      else if (first_hand == 'G' && second_hand == 'P')
      {
        results[2 * j + 1].first++;
      }
    }
    // cout << "!" << endl;
    sort(results.begin(), results.end(), [](pair<ll, ll> l, pair<ll, ll> r)
         {
           if (l.first == r.first)
           {
             return l.second < r.second;
           }
           else
           {
             return l.first > r.first;
           }
         });
  }
  // for (int i = 0; i < 2 * N; i++)
  // {
  //   cout << results[i].first << ":" << results[i].second << endl;
  // }
  for (int i = 0; i < 2 * N; i++)
  {
    cout << results[i].second + 1 << endl;
  }
  return 0;
}