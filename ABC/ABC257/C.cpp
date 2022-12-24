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
  string S;
  cin >> N >> S;
  vector<pair<ll, bool>> W(N);
  ll adult_count = 0;
  ll child_count = 0;
  for (int i = 0; i < N; i++)
  {
    ll w;
    cin >> w;
    W[i] = {w, S[i] == '1'};
    if (S[i] == '1')
    {
      adult_count++;
    }
  }
  // cout << adult_count << endl;
  ll ans = 0;
  sort(W.begin(), W.end());
  W.push_back({numeric_limits<ll>::max(), false});
  N++;
  ll index = 0;
  while (index < N)
  {
    // cout << index << ":" << adult_count << "," << child_count << endl;
    ans = max(ans, adult_count + child_count);
    ll w = W[index].first;
    while (index < N && W[index].first == w)
    {
      if (W[index].second)
      {
        adult_count--;
      }
      else
      {
        child_count++;
      }
      index++;
    }
  }
  cout << ans << endl;
  return 0;
}