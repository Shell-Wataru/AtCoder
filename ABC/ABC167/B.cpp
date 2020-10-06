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
  ll A,B,C,K;
  cin >> A >> B >> C >> K;
  ll total = 0;
  total += min(A,K);
  K -= min(A,K);
  K -= min(B,K);
  total -= min(C,K);
  K -= min(C,K);
  cout << total << endl;
  return 0;
}