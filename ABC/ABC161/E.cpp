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
ll BASE_NUM = 1000000007;

set<ll> must_work_days(string &S, int N, int K, int C, int from)
{
  set<ll> ans;

  for (int i = from; i < N - (K - 1) * (C + 1); i++)
  {
    must_work_days(S, N, K - 1, C, from + C + 1);
  }
  return ans;
}
int main()
{
  // 整数の入力
  ll N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;
  set<ll> ans = must_work_days(S, K, C, 0);
  return 0;
}
