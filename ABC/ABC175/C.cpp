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
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  ll total = 0;
  ll max_height = A[0];
  for(int i = 1; i < N;i++){
    if (max_height > A[i]){
      total += max_height - A[i];
    }else{
      max_height = A[i];
    }
  }
  cout << total << endl;
  return 0;
}