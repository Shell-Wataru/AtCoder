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
#include <set>
using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N, X, M;
  cin >> N >> X >> M;
  vector<ll> periods;
  set<ll> used;
  periods.push_back(X);
  while (used.find((X * X) % M) == used.end())
  {
    X = X * X % M;
    used.insert(X);
    periods.push_back(X);
  }
  ll period_start_number = X * X % M;
  bool period_started = false;
  vector<ll> period_sums;
  vector<ll> head_sums;
  period_sums.push_back(0);
  head_sums.push_back(0);
  for (int i = 0; i < periods.size(); i++)
  {
    if (periods[i] == period_start_number)
    {
      period_started = true;
    }
    if (period_started)
    {
      period_sums.push_back(period_sums.back() + periods[i]);
    }
    else
    {
      head_sums.push_back(head_sums.back() + periods[i]);
    }
  }

  ll remain = N;
  ll head = min((ll)head_sums.size() - 1, remain);
  remain = remain - head;
  ll period_times = remain / (period_sums.size() - 1);
  ll period_remain = remain % (period_sums.size() - 1);
  // cout << head << " " << period_times << " " << period_remain << endl;
  cout << head_sums[head] + period_sums.back() * period_times + period_sums[period_remain] << endl;
  return 0;
}
