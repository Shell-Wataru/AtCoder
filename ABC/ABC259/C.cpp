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
  string S, T;
  cin >> S >> T;
  vector<pair<char, ll>> runlength_s;
  vector<pair<char, ll>> runlength_t;
  for (auto c : S)
  {
    if (runlength_s.empty() || runlength_s.back().first != c)
    {
      runlength_s.push_back({c, 1});
    }
    else
    {
      runlength_s.back().second++;
    }
  }
  for (auto c : T)
  {
    if (runlength_t.empty() || runlength_t.back().first != c)
    {
      runlength_t.push_back({c, 1});
    }
    else
    {
      runlength_t.back().second++;
    }
  }
  if (runlength_s.size() != runlength_t.size())
  {
    cout << "No" << endl;
  }
  else
  {
    for (int i = 0; i < runlength_s.size(); i++)
    {
      if (runlength_s[i].first == runlength_t[i].first &&
          (runlength_s[i].second == runlength_t[i].second || runlength_s[i].second >= 2 && runlength_s[i].second <= runlength_t[i].second))
      {
        continue;
      }
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
  }
  return 0;
}