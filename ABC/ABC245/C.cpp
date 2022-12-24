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
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> B(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  for(int i = 0;i < N;i++){
    cin >> B[i];
  }
  bool last_a = true;
  bool last_b = true;
  for(int i = 0;i < N;i++){
    if(i == 0){
      last_a = true;
      last_b = true;
    }else{
      bool next_last_a = false;
      bool next_last_b = false;
      if (last_a){
        if (abs(A[i-1] - A[i]) <= K){
          next_last_a = true;
        }
        if (abs(A[i-1] - B[i]) <= K){
          next_last_b = true;
        }
      }
      if (last_b){
        if (abs(B[i-1] - A[i]) <= K){
          next_last_a = true;
        }
        if (abs(B[i-1] - B[i]) <= K){
          next_last_b = true;
        }
      }
      last_a = next_last_a;
      last_b = next_last_b;
    }
  }
  if (last_a || last_b){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}