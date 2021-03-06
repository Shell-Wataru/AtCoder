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
  double ans = 0;
  for (int i = 1; i < N; i++)
  {
    ans += 1.0 *  N/(N - i);
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
