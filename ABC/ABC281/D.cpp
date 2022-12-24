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
#include <unordered_set>
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,K,D;
  cin >> N >> K >> D;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  vector<unordered_map<ll,ll>> DP(K+1);
  DP[0][0] = 0;
  for(int i = 0;i < N;i++){
    for(int j=K-1;j>=0;j--){
      for(auto k:DP[j]){
        DP[j+1][(k.first+A[i] % D)] = max(DP[j+1][(k.first+A[i] % D)],(k.second+A[i]));
      }
    }
  }
  ll ans = -1;
  for(auto k:DP[K]){
    // cout << k << endl;
    if (k.first % D == 0){
      ans = max(ans,k.second);
    }
  }
  cout << ans << endl;
  return 0;
}