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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  vector<ll> B(M);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }

  for(int i = 0;i < M;i++){
    cin >> B[i];
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  ll a_index = 0;
  ll b_index = 0;
  ll ans = numeric_limits<ll>::max();
  while(true){
    ans = min(ans,abs(A[a_index] - B[b_index]));
    if (a_index == N -1 && b_index == M -1){
      break;
    }else if (a_index == N-1){
      b_index++;
    }else if (b_index == M-1){
      a_index++;
    }else if(A[a_index] < B[b_index]){
      a_index++;
    }else if(A[a_index] > B[b_index]){
      b_index++;
    }else{
      break;
    }
  }
  cout << ans << endl;
  return 0;
}