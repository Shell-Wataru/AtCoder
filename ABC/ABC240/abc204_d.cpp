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
  vector<ll> T(N);
  vector<bool> currentDP(100001,false);
  vector<bool> nextDP(100001,false);
  ll total = 0;
  for(int i = 0;i < N;i++){
      cin >> T[i];
      total += T[i];
  }

  currentDP[0] = true;
  for(int i = 0;i < N;i++){
      nextDP = currentDP;
      for(int j = 0; j + T[i]< 100001;j++){
          if(currentDP[j]){
              nextDP[j+T[i]] = true;
          }
      }
      swap(currentDP,nextDP);
  }
  ll ans = numeric_limits<ll>::max();
  for(ll i = 0; i <  100001;i++){
      if (currentDP[i]){
          ans = min(ans,max(i,total-i));
      }
  }
  cout << ans << endl;
  return 0;
}