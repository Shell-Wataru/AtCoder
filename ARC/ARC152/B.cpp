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
#include <climits>
#include <atcoder/string>

using namespace std;
using ll = long long;
using namespace atcoder;

int solve(){
  ll N,L;
  cin >> N >> L;
  vector<ll> a(N);
  for(int i = 0;i < N;i++){
    cin >> a[i];
  }
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i < N;i++){
    ll index = lower_bound(a.begin(),a.end(),L-a[i]) - a.begin();
    if (index == N){
      // cout << "!" << endl;
      ans = min(ans,2*(a[i]+L+(L-a[N-1])) );
      index--;
      ans = min(ans,2*((L-a[i])+(L-a[index])));
    }else if (index == 0){
      ans = min(ans,2*(a[i]+a[index]));
      ans = min(ans,2*((L-a[i])+L+a[index]));
    }else{
      ans = min(ans,2*(a[i]+a[index]));
      index--;
      ans = min(ans,2*((L-a[i])+(L-a[index])));
    }
  }
  cout << ans << endl;
  return 0;
}
int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 0;i < N;i++){
      solve();
    // }
    cout << flush;
    return 0;
}