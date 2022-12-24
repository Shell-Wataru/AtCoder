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
#include <stack>

using namespace std;
using ll = long long;

ll answer(ll l,ll r,ll K, vector<ll> &A){
  // cout << l << "-" << r << endl;
  if (l+1 == r){
    return l;
  }
  ll center = (l+r)/2;
  ll count = 0;
  for(auto a:A){
    count += min(center,a);
  }
  // cout << count << endl;
  if (count/K >= center){
    return answer(center,r,K,A);
  }else{
    return answer(l,center,K,A);
  }
}

int main()
{
  // 整数の入力
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  cout << answer(0,numeric_limits<ll>::max(),K,A) << endl;
  return 0;
}
