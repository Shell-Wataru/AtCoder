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
  ll X ,Y , R;
  cin >> R >> X >> Y;
  ll d2 = X*X + Y*Y;
  ll ans = -1;
  for(ll i = 0;i < 500000;i++){
    if (d2 == i*i * R * R){
      cout << i << endl;
      return 0;
    }else if (d2 < i*i * R * R){
      if (i == 1){
        cout << 2 << endl;
        return 0;
      }else{
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}