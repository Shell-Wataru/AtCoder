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

ll LIS(vector<pair<ll,ll>> &AB){
  ll N = AB.size();
  vector<ll> DP(N+2,numeric_limits<ll>::max());
  DP[0] = 0;
  for(int i = 0;i < N;i++){
    ll j = upper_bound(DP.begin(),DP.end(),AB[i].second) - DP.begin();
    DP[j] = AB[i].second;
  }
  return upper_bound(DP.begin(),DP.end(),numeric_limits<ll>::max()-1) - DP.begin() - 1;
}
int main()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> AB(N);
    vector<pair<ll,ll>> BA(N);
    for(int i = 0;i< N;i++){
      cin >> AB[i].first;
      BA[i].second = AB[i].first;
    }
    for(int i = 0;i< N;i++){
      cin >> AB[i].second;
      BA[i].first = AB[i].second;
    }
    sort(AB.begin(),AB.end());
    sort(BA.begin(),BA.end());
    // for(int i = 0;i < N;i++){
    //   cout << AB[i].second << ",";
    // }
    // cout << endl;
    ll ans = max(LIS(AB),LIS(BA)) + N;
    cout << ans << endl;
    return 0;
}