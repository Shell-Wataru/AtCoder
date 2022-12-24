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
  set<ll> unused;
  for(int i = 1;i <= 2*N+1;i++){
    unused.insert(i);
  }
  for(int i = 0;i <= N;i++){
    ll takahashi =  *unused.begin();
    cout << takahashi << endl;
    ll aoki;
    cin >> aoki;
    unused.erase(takahashi);
    unused.erase(aoki);
    if (aoki == 0){
      break;
    }
  }
  return 0;
}