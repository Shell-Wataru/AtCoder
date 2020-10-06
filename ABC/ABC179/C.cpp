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


const long long BASE_NUM = 1000000007;

int main()
{
  ll N;
  cin >> N;
  ll ans = 0;
  for(int i = 1;i<= N;i++){
    ans += (N-1)/i;
  }
  cout << ans << endl;
  return 0;
}