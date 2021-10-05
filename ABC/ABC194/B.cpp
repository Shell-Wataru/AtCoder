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
  ll N,X;
  cin >> N;
  vector<pair<ll,ll>> A(N);
  vector<pair<ll,ll>> B(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i].first;
    cin >> B[i].first;
    A[i].second = i;
    B[i].second = i;
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  if (A[0].second != B[0].second){
    cout << max(A[0].first, B[0].first) << endl;
  }else{
    cout << min(A[0].first + B[0].first , min(max(A[0].first, B[1].first),max(A[1].first, B[0].first))) << endl;
  }
 return 0;
}