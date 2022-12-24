#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <numeric>
using namespace std;
using ll = long long;

string solve()
{
  ll N;
  cin >> N;
  vector<pair<ll,ll>> children(N);
  vector<pair<ll,ll>> candies(N + 1);
  for (int i = 0; i < N; i++)
  {
    cin >> children[i].first >> children[i].second;
  }
  for (int i = 0; i <= N; i++)
  {
    cin >> candies[i].first >> candies[i].second;
  }
  vector<ll> DPbacktrace(1ll<<(2*N+1));
  vector<bool> DP(1ll<<(2*N+1),false);
  DP[0] = true;
  for(ll i = 0;i < 1ll<<(2*N+1);i++){
    if (DP[i]){
      for(int j = 0;j < N;j++){
        if (!(i & 1ll<<j)){
          ll min_d = numeric_limits<ll>::max();
          for(int k = 0;k <= N;k++){
            if(!(i & 1ll<<(N+k))){
              ll x = children[j].first - candies[k].first;
              ll y = children[j].second - candies[k].second;
              min_d = min(min_d,x*x+y*y);
            }
          }
          for(int k = 1;k <= N;k++){
            if(!(i & 1ll<<(N+k))){
              ll x = children[j].first - candies[k].first;
              ll y = children[j].second - candies[k].second;
              ll d = x*x+y*y;
              if (d <= min_d){
                DP[i | 1ll<<j | 1ll<<(N+k)] = true;
                DPbacktrace[i | 1ll<<j | 1ll<<(N+k)] = i;
              }
            }
          }
        }
      }
    }
  }
  if (DP[((1ll<<(2*N+1))-1) ^ (1ll<<N)]){
    ll current = ((1ll<<(2*N+1))-1) ^ (1ll<<N);
    vector<pair<ll,ll>> answers;
    while(current != 0){
      ll next_i = DPbacktrace[current];
      ll from;
      ll to;
      for(int i = 0;i < N;i++){
        if ((next_i^current) & 1ll<<i){
          from = i;
        }
      }
      for(int i = N+1;i < 2*N+1;i++){
        if ((next_i^current) & 1ll<<i){
          to = i-N;
        }
      }
      answers.push_back({from,to});
      current = next_i;
    }
    string ans = "POSSIBLE\n";
    for(int i = N-1;i >=0;i--){
      ans += to_string(answers[i].first+1) + " " + to_string(answers[i].second+1) + "\n";
    }
    return ans;
  }else{
    return "IMPOSSIBLE\n";
  }

}
int main()
{
  // 整数の入力
  ll T;
  cin >> T;

  for (int i = 1; i <= T; i++)
  {
    string ans = solve();
    cout << "Case #" << i << ": " << ans << flush;
  }

  return 0;
}