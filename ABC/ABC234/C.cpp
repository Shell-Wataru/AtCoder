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
  ll K;
  cin >> K;
  for(int i = 60;i >= 0;i--){
    if ((1ll<<i & K)){
      cout << 2;
    }else if (1ll<<i <= K){
      cout << 0;
    }
  }
  cout << endl;
  return 0;
}