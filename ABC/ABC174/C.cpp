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
  ll K;
  cin >> K;
  set<ll> visited;
  ll current = 0;
  ll ans = 0;
  bool found = false;
  while(true){
    current = (current * 10 + 7) % K;
    ans++;
    if (current == 0){
      found = true;
      break;
    }else if(visited.find(current) != visited.end()){
      break;
    }else{
      visited.insert(current);
    }
  }
  if (found){
    cout << ans << endl;
  }else{
    cout << "-1" << endl;
  }
  return 0;
}