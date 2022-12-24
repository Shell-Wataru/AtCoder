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
  ll x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  set<pair<ll,ll>> a = {
    {x1+1,y1+2},
    {x1+2,y1+1},
    {x1+1,y1-2},
    {x1+2,y1-1},
    {x1-1,y1+2},
    {x1-2,y1+1},
    {x1-1,y1-2},
    {x1-2,y1-1}
  };
  set<pair<ll,ll>> b = {
    {x2+1,y2+2},
    {x2+2,y2+1},
    {x2+1,y2-2},
    {x2+2,y2-1},
    {x2-1,y2+2},
    {x2-2,y2+1},
    {x2-1,y2-2},
    {x2-2,y2-1}
  };
  bool found = false;
  for(auto p:b){
    if (a.find(p) != a.end()){
      found = true;
    }
  }
  if (found){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}