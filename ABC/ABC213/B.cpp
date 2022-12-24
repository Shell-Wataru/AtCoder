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
  vector<pair<ll,ll>> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(),A.end());
  cout << A[N-2].second + 1 << endl;
  return 0;
}