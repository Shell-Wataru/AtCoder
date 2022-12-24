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
  string ans = "";
  for(int i = 59;i>= 0;i--){
    ans +='B';
    if (N & 1ll<<i){
      ans+= 'A';
    }
  }
  cout << ans << endl;
  return 0;
}