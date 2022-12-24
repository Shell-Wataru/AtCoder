#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{
  string S,T;
  cin >> S >> T;
  ll n = S.size();
  ll m = T.size();
  vector<pair<ll,ll>> DP(n+1,{numeric_limits<ll>::max()/2,0});
  DP[0] = {0,1};
  for(int i = 0; i+m <= n;i++){
    if (S.substr(i,m) == T){
      for(int j = i;j>=0;j--){
        if (j+m <= i && S.substr(j,m) == T){
          break;
        }else{
          if (DP[i+m].first == DP[j].first+1){
            DP[i+m].second += DP[j].second;
            DP[i+m].second %= 1000000007;
          }else if (DP[j].first+1 < DP[i+m].first){
            // cout << j << endl;
            DP[i+m].first = DP[j].first+1;
            DP[i+m].second = DP[j].second;
          }
        }
      }
    }
  }
  ll ans = 0;
  ll addition = numeric_limits<ll>::max()/2;
  for(int j = n;j>=0;j--){
    if (j+m <= n && S.substr(j,m) == T){
      break;
    }else{
      if (addition == DP[j].first){
        ans += DP[j].second;
        ans %= 1000000007;
      }else if (DP[j].first < addition ){
        addition = DP[j].first;
        ans = DP[j].second;
      }

    }
  }
  cout  << addition << " " << ans << endl;
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}