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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  ll total = 0;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    total += A[i];
  }
  sort(A.begin(),A.end(),greater<ll>());
  bool can_select = true;
  for(int i = 0;i < M;i++){
    if(4 * M *A[i] < total){
      can_select = false;
      break;
    }
  }
  if(can_select){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
 return 0;
}