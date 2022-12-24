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
  ll N,Q;
  cin >> N;
  vector<string> S(N);
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i < 10;i++){
    vector<ll> seconds(10,0);
    for(int j = 0;j < N;j++){
      for(int k = 0;k < 10;k++){
        if (S[j][k] - '0' == i){
          seconds[k]++;
        }
      }
    }
    ll t = 0;
    for(int j = 0;j <= 100;j++){
      for(int k = 0;k < 10;k++){
        if (seconds[k] > 0){
          seconds[k]--;
          t = 10*j + k;
        }
      }
    }
    ans = min(ans,t);
  }
  cout << ans << endl;
   return 0;
}