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

using namespace std;
using ll = long long;

ll solve(ll l,ll r, vector<ll> &A,ll k){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
  ll index = lower_bound(A.begin(),A.end(),center) - A.begin();
  ll count = center - index;
  if (index == A.size() || A[index] != center){
    if (count >= k){
      return solve(l,center,A,k);
    }else{
      return solve(center,r,A,k);
    }
  }else{
    if (count > k){
      return solve(l,center,A,k);
    }else{
      return solve(center,r,A,k);
    }
  }
}

int main()
{
  // 整数の入力
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  for(int i = 0;i < Q;i++){
    ll k;
    cin >> k;
    cout << solve(0,numeric_limits<ll>::max(),A,k) << endl;
  }
  return 0;
}
