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
  ll A,B,N;
  cin >> A >> B >> N;
  ll x = min(B-1,N);
  cout << A* x/B - A *( x/ B) << endl;
  return 0;
}