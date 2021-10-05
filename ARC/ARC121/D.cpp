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

ll min_time(vector<ll> &A,ll l, ll r){
  if (l+ 1 == r){
    return r;
  }
  ll N = A.size();
  ll center = (l+r)/2;
  ll last_time = center;
  ll last_position = A[0]+center;
  for(int i = 1;i < N;i++){
    if (i % 2 == 1){
      ll diff = center + last_position - A[i];
      if (diff < 0){
        return min_time(A,center,r);
      }
      last_position = A[i] + diff/2;
      last_time = diff/2;
    }else{
      if (A[i] - last_position > last_time){
        return min_time(A,center,r);
      }else{
        last_position = last_position + (center - last_time);
        last_time = center;
      }
    }
  }
  return min_time(A,l,center);
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
  cout << min_time(A,0,numeric_limits<ll>::max()/2) << endl;
  return 0;
}