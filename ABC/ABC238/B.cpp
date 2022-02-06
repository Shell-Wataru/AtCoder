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

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> cuts = {0,360};
  ll current = 0;
  for (int i = 0; i < N; i++)
  {
    ll a;
    cin >> a;
    current += a;
    current %= 360;
    cuts.push_back(current);
  }
  sort(cuts.begin(), cuts.end());
  ll max_a = 0;
  // for (int i = 0; i < N; i++)
  // {
  //   cout << cuts[i] << endl;
  // }
  for (int i = 0; i <= N; i++)
  {
    max_a = max(max_a, abs(cuts[i] - cuts[i+1]));
  }
  cout << max_a << endl;
  return 0;
}