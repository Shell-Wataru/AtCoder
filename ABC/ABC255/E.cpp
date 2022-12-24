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
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll N,M;
  cin >> N >> M;
  vector<ll> S(N);
  vector<ll> X(M);
  for(int i = 0;i < N-1;i++){
    cin >> S[i];
  }
  for(int i = 0;i < M;i++){
    cin >> X[i];
  }
  unordered_map<ll,ll> counts_plus;
  unordered_map<ll,ll> counts_minus;
  ll current = 0;
  counts_plus[current]++;
  for(int i = 0;i < N-1;i++){
    current = S[i] -current;
    if (i % 2 == 0){
      counts_minus[current]++;
    }else{
      counts_plus[current]++;
    }
  }
  ll ans = 0;
  for(auto p:counts_plus){
    for(auto x1:X){
      ll a = x1 - p.first;
      ll current_ans = 0;
      for(auto x2:X){
        if (counts_plus.count(x2-a) == 1){
          current_ans += counts_plus[x2-a];
        }
        if (counts_minus.count(x2+a) == 1){
          current_ans += counts_minus[x2+a];
        }
      }
      ans = max(ans,current_ans);
    }
  }

  for(auto p:counts_minus){
    for(auto x1:X){
      ll a = x1 + p.first;
      ll current_ans = 0;
      for(auto x2:X){
        if (counts_plus.count(x2-a) == 1){
          current_ans += counts_plus[x2-a];
        }
        if (counts_minus.count(x2+a) == 1){
          current_ans += counts_minus[x2+a];
        }
      }
      ans = max(ans,current_ans);
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
