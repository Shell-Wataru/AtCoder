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
  ll r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  ll x = abs(r1-r2);
  ll y = abs(c1-c2);
  if(x + y == 0){
    cout << 0 << endl;
  }else if(x + y <= 3){
    cout << 1 << endl;
  }else if (abs(x-y) == 0){
    cout << 1 << endl;
  }else if(abs(x-y) <= 3){
    cout << 2 << endl;
  }else if((x + y) % 2 == 0){
    cout << 2 << endl;
  }else{
    cout << 3 << endl;
  }
  return 0;
}