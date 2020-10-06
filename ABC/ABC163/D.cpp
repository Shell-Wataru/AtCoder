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

ll BASE_NUM = 1000000007;
int main()
{
  // 整数の入力
  ll N, K;
  cin >> N >> K;
  ll total = 0;
  for (ll i = K; i <= N + 1; i++)
  {
    ll min_sum = i * (i - 1) / 2;
    ll max_sum = i * (N + (N - i) + 1) / 2;
    // cout << i << endl;
    // cout << min_sum << " " << max_sum << endl;
    total = (total + max_sum - min_sum + 1) % BASE_NUM;
  }
  cout << total << endl;
  return 0;
}