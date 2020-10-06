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
ll BASE_NUM = 1000000007;

int main()
{
  ll N,M, K;
  cin >> N >> M >> K;
  vector<ll> A(N+1,0);
  vector<ll> B(M+1,0);
  for(int i = 1;i <= N;i++){
    ll a;
    cin >> a;
    A[i] += A[i-1] + a;
  }
  for(int i = 1;i <= M;i++){
    ll b;
    cin >> b;
    B[i] += B[i-1] + b;
  }
  ll ans = 0;
  ll b_books = M;
  for(int i = 0;i <= N;i++){
    while(b_books >= 0 && A[i] + B[b_books] > K){
      b_books--;
    }
    if (b_books >= 0){
      ans = max(ans,i+b_books);
    }
  }
  cout << ans << endl;
  return 0;
}