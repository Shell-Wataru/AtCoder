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
  ll Q;
  cin >> Q;
  map<ll,ll> counts;
  for(int i = 0;i < Q;i++){
    ll t;
    cin >> t;
    if (t == 1){
      ll x;
      cin >> x;
      counts[x]++;
    }else if(t == 2){
      ll x,c;
      cin >> x>>c;
      counts[x] -= c;
      if (counts[x] <= 0){
        counts.erase(x);
      }
    }else{
      cout <<  counts.rbegin()->first - counts.begin()->first << endl;
    }
  }
   return 0;
}