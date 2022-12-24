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
  ll N,K,X;
  cin >> N >> K >> X;
  vector<ll> A(N);
  priority_queue<ll> remains;
  ll used = 0;
  ll total = 0;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    total += A[i];
    // cout << "!" << A[i] / X << "," << K<< endl;
    remains.push(A[i] - min(K,A[i]/X) * X);
    used += min(K,A[i]/X) * X;
    K -= min(K,A[i]/X);
  }
  while(K > 0 && !remains.empty()){
    K--;
    used += remains.top();
    remains.pop();
  }
  cout << total - used << endl;
  return 0;
}