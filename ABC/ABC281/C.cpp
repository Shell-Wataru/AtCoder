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
#include <unordered_map>
#include <unordered_set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,T;
  cin >> N >> T;
  vector<ll> A(N);
  vector<ll> cumA(N+1);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    cumA[i+1] = cumA[i]+ A[i];
  }
  T %=  cumA[N];
  auto iter = lower_bound(cumA.begin(),cumA.end(),T);
  iter--;
  cout << iter - cumA.begin() + 1 << " " << T- *iter << endl;
  return 0;
}