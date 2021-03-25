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

int main()
{
  // 整数の入力
  ll A, B, W;
  cin >> A >> B >> W;
  ll min_ans = numeric_limits<ll>::max();
  ll max_ans = numeric_limits<ll>::min();
  W *= 1000;
  for (ll i = 0; i <= 2000000; i++)
  {
    if (A * i <= W && W <= B * i)
    {
      min_ans = min(min_ans, i);
      max_ans = max(max_ans, i);
    }
  }
  if (min_ans == numeric_limits<ll>::max())
  {
    cout << "UNSATISFIABLE" << endl;
  }
  else
  {
    cout << min_ans << " " << max_ans << endl;
  }
  return 0;
}