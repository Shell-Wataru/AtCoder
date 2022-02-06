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
  vector<pair<ll,ll>> P(N);
  for(int i = 0;i < N;i++){
    cin >> P[i].first >> P[i].second;
  }
  ll ans = 0;
  for(int i = 0;i < N;i++){
    for(int j = i+1;j < N;j++){
      for(int k = j+1;k < N;k++){
        ll x1 = P[j].first - P[i].first;
        ll y1 = P[j].second - P[i].second;
        ll x2 = P[k].first - P[i].first;
        ll y2 = P[k].second - P[i].second;
        if (x1 * y2 - y1*x2 != 0){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}