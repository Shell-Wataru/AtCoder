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

int main()
{
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll i = 1;i *i*i <= N;i++){
    ll remain = N/i;
    for(ll j = i;j * j <= remain;j++){
      ans += remain/j - j + 1;
    }
  }
  cout << ans << endl;
  return 0;
}