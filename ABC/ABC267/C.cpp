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
  ll M,N;
  cin >> N >> M;
  vector<ll> A(N);
  for(int i = 0;i < N;i++ ){
    cin >> A[i];
  }
  vector<ll> cumA(N+1);
  for(int i = 0;i < N;i++){
    cumA[i+1] = cumA[i] + A[i];
  }
  ll current = 0;
  for(int i = 0;i < M;i++){
    // cout << (i+1)*A[N-M+i] << ",";
    current += (i+1)*A[N-M+i];
  }
  // cout << endl;
  // cout << current << endl;
  ll ans = current;
  for(int i = N-M-1;i >= 0;i--){
    current += cumA[i+M]-cumA[i] - A[i+M]*M;
    // cout << current << endl;
    ans = max(ans,current);
  }
  cout << ans << endl;
  return 0;
}