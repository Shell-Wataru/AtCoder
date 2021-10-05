#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld", &p[i]);
  }
  map<ll, ll> daniels_moves;
  vector<pair<ll, ll>> qingshan_candidates;
  vector<ll> mountains;
  for (int i = 0; i < n; i++)
  {
    if (i == 0 || i == n - 1 || (p[i - 1] < p[i] && p[i] > p[i + 1]) || (p[i - 1] > p[i] && p[i] < p[i + 1]))
    {
      // cout << i << endl;
      mountains.push_back(i);
    }
  }

  ll max_slope = 0;
  for (int i = 1; i < mountains.size(); i++)
  {
    max_slope = max(max_slope,mountains[i] - mountains[i-1]);
    daniels_moves[mountains[i] - mountains[i-1]]++;
    if ((0 <= i-1 && i + 1 < mountains.size())  && p[mountains[i-1]] < p[mountains[i]] && p[mountains[i]]  > p[mountains[i+1]])
    {
      qingshan_candidates.push_back({mountains[i] - mountains[i-1],mountains[i+1] - mountains[i]});
    }
  }
  bool has_max_slope_pair = false;
  for(auto &p:qingshan_candidates) {
    // cout << p.first << "~" << p.second << endl;
    if (p.first == max_slope && p.second == max_slope){
      has_max_slope_pair = true;
      break;
    }
  }
  // cout << max_slope << endl;
  // cout << has_max_slope_pair << endl;
  if (has_max_slope_pair && max_slope % 2 == 0 && daniels_moves[max_slope] == 2){
    cout << 1 << "\n";
  }else{
    cout << 0 << "\n";
  }
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;

  // for (int i = 1; i <= t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}