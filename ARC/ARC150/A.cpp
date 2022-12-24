#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve()
{
  ll N,K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<pair<char,ll>>runlength;
  bool one_found = false;
  for(int i = 0;i < N;i++){
    if (S[i] == '1'){
      one_found = true;
    }
    if (runlength.empty() || runlength.back().first != S[i]){
      runlength.push_back({S[i],1});
    }else{
      runlength.back().second++;
    }
    if (runlength.size() >= 3){
      if (runlength[runlength.size()-3].first == '1' && runlength[runlength.size()-2].first == '?' && runlength[runlength.size()-1].first == '1'){
        ll a = runlength.back().second;
        runlength.pop_back();
        ll b = runlength.back().second;
        runlength.pop_back();
        runlength.back().second += a+b;
      }
    }
  }
  if (one_found){
    ll one_count = 0;
    bool is_ok = false;
    for(int i = 0;i < runlength.size();i++){
      if (runlength[i].first == '1'){
        one_count++;
        ll min_l = runlength[i].second;
        ll max_l = runlength[i].second;
        bool both_open = (i-1>= 0 && runlength[i-1].first == '?') && (i+1 < runlength.size() && runlength[i+1].first == '?');
        if (i-1>= 0 && runlength[i-1].first == '?'){
          max_l += runlength[i-1].second;
        }
        if (i+1 < runlength.size() && runlength[i+1].first == '?'){
          max_l += runlength[i+1].second;
        }
        if ( (both_open && (max_l == K || min_l == K)) || (!both_open && min_l <= K &&  K <= max_l)){
          is_ok = true;
        }
      }
    }
    if (is_ok && one_count == 1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    ll patterns = 0;
    for(int i = 0;i < runlength.size();i++){
      if (runlength[i].first == '?'){
        patterns += max(0ll,runlength[i].second - K +1);
      }
    }
    if (patterns == 1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

  return 0;
}
int main()
{
  ll T;
  cin >> T;
  for(int i = 0;i < T;i++){
    solve();
  }
  cout << flush;
  return 0;
}