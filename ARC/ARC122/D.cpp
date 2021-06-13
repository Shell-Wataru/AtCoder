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

ll answer(ll l,ll r, vector<ll> &A){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
}

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  cout << answer(-1,10000000000ll,A) << endl;;
  return 0;
}