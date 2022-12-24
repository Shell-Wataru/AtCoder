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


int solve()
{
  ll N,L,R;
  cin >> N >> L >> R;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  vector<ll> ruisekiWa(N+1,0);
  for(int i = 0;i < N;i++){
    ruisekiWa[i+1] = ruisekiWa[i] + A[i];
  }
  vector<ll> minL(N+1,0);
  vector<ll> minR(N+1,0);
  for(int i = 0;i < N;i++){
      minL[i+1] = min(minL[i]+A[i],L*(i+1));
  }
  for(int i = N-1;i >= 0;i--){
      minR[i] = min(minR[i+1]+A[i],R*(N-i));
  }
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i <= N;i++){
    ans = min(ans,minL[i]+minR[i]);
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
