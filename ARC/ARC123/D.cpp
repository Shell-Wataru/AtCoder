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
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> plusSumA(N+1,0);
  vector<ll> minusSumA(N+1,0);
  vector<ll> B(N);
  vector<ll> C(N);
  ll total = 0;
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  for(int i =0 ;i < N;i++){
    if (A[i] > 0){
      plusSumA[i+1] += plusSumA[i] + A[i];
      minusSumA[i+1] += minusSumA[i];
    }else{
      plusSumA[i+1] += plusSumA[i];
      minusSumA[i+1] += minusSumA[i] + A[i];
    }
  }
  ll last_b = 0;
  for(int i = 0;i < N;i++){
    B[i] = last_b + A[i];
    last_b = B[i];
  }
  ll last_c = 0;
  for(int i = N-1;i >= 0;i--){
    C[i] = last_c + A[i];
    last_c = C[i];
  }
  return 0;
}