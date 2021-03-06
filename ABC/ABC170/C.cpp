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
  ll X,N;
  cin >> X >> N;
  set<ll> P;
  for (size_t i = 0; i < N; i++)
  {
    ll p;
    cin >> p;
    P.insert(p);
  }
  ll min_diff = BASE_NUM;
  ll min_v = -1;
  for(int i = 0;i <= 101;i++){
    if (min_diff > abs(X - i) && P.find(i) == P.end()){
      min_v = i;
      min_diff = abs(X - i);
    }
  }
  cout << min_v << endl;

  return 0;
}