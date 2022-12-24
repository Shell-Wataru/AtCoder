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
#include <set>
using namespace std;
using ll = long long;

ll lte_sqrt(ll X){
  ll a = sqrt(X);
  if ( (a + 1) * (a+1) <= X ){
    return a + 1;
  }else if (a * a <= X){
    return a;
  }else{
    return a - 1;
  }
}

ll solve(ll X){
  ll ans = 0;
  while(X != 1){
    X = lte_sqrt(X);
    ans += X;
  }
  ans++;
  return ans;
}

ll naive(ll N){
  vector<ll> DP(N+1);
  DP[1] = 1;
  for(int i = 2;i <= N;i++){
    for(int j = 1;j*j <= i;j++){
      DP[i] += DP[j];
    }
  }
  return DP[N];
}
int main()
{
  ll N;
  cin >> N;
  for(int i = 1; i <= N;i++){
    cout << i << ":" << endl;
    cout <<  " solve:" << solve(i) << endl;
    cout <<  " naive:" << naive(i) << endl;
  }
  cout << flush;
  return 0;
}
