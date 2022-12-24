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

using namespace std;
using ll = long long;


ll value(vector<pair<ll, ll>> &ranges, ll center){
  ll N = ranges.size();
  vector<ll> x;
  for (int i = 0; i < N; i++)
  {
    if (ranges[i].second < center)
    {
      x.push_back(ranges[i].second);
    }
    else if (ranges[i].first > center)
    {
      x.push_back(ranges[i].first);
    }
    else
    {
      x.push_back(center);
    }
  }
  sort(x.begin(), x.end());
  // for (auto xx : x)
  // {
  //   cout << xx << ",";
  // }
  // cout << endl;
  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += (2 * i - N + 1) * x[i];
  }
  return ans;
}

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll, ll>> ranges(N);
  for (int i = 0; i < N; i++)
  {
    cin >> ranges[i].first >> ranges[i].second;
  }
  ll l = 0;
  ll r = 10000001;
  while (l + 1 < r)
  {
    ll center = (l + r) / 2;
    ll smaller = 0;
    ll bigger = 0;
    ll middle = 0;
    for (int i = 0; i < N; i++)
    {
      if (ranges[i].second < center)
      {
        smaller++;
      }
      else if (ranges[i].first > center)
      {
        bigger++;
      }
      else
      {
        middle++;
      }
    }
    if (smaller >= bigger)
    {
      r = center;
    }
    else
    {
      l = center;
    }
  }
  cout << min(value(ranges,l),value(ranges,r)) << endl;
  return 0;
}
