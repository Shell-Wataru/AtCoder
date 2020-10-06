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
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力

  double A, B, H, M;
  cin >> A >> B >> H >> M;
  double theta = 2.0 * M_PI * (H + M / 60) / 12 - 2.0 * M_PI * M / 60;
  double d = sqrt(A * A + B * B - 2 * A * B * cos(theta));
  cout << fixed << setprecision(12) << d << endl;
  return 0;
}