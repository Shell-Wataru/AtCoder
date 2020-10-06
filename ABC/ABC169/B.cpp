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
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  if (A[0] == 0){
    cout << 0 << endl;
  }else{
    ll ans = 1;
    for(int i = 0;i < N;i++){
      if (A[i] > 1000000000000000000ll/ans){
        ans = -1;
        break;
      }else{
        ans *= A[i];
        // cout << ans << endl;
      }
    }
    cout << ans << endl;
  }
  return 0;
}