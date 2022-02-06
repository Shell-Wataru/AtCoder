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


int main()
{
  // 整数の入力
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    A[i]--;
  }
  vector<vector<ll>> DP1(N,vector<ll>(K,numeric_limits<ll>::max()));
  vector<vector<ll>> DP2(N,vector<ll>(K,numeric_limits<ll>::max()));
  for(int i = 0;i < N;i++){
    if (A[i] == 0){
      DP1[i][0] = 0;
    }else{
      for(int j = i-1;j>=0;j--){
        if (A[j] == A[i]-1){
          DP1[i][A[i]] = min(DP1[i][A[i]],DP1[j][A[j]] + (i-j-1)*A[i]);
        }
      }
    }
  }
  for(int i = N-1;i >= 0;i--){
    if (A[i] == K-1){
      DP2[i][K-1] = 0;
    }else{
      for(int j = i+1;j<N;j++){
        if (A[j] == A[i]+1){
          DP2[i][A[i]] = min(DP2[i][A[i]],DP2[j][A[j]] + (j-i-1)*(K-1-A[i]));
        }
      }
    }
  }
  ll ans = numeric_limits<ll>
  return 0;
}