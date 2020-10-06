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
int BASE_NUM = 998244353;

int solve()
{
  ll n;
  scanf("%lld",&n);
  string S;
  cin >> S;
  vector<pair<char,ll>> A;
  for(int i = 0;i < n;i++){
    if (A.empty()){
      A.push_back({S[i],1});
    }else if (A.back().first == S[i]){
      A.back().second++;
    }else{
      A.push_back({S[i],1});
    }
  }
  if (A.size() == 1){
    cout << (A.front().second - 1)/3 + 1 << endl;
  }else{
    if (A.front().first == A.back().first){
      A.front().second += A.back().second;
      A.pop_back();
    }
    ll ans = 0;
    for(auto p:A){
      ans += p.second/3;
    }
    cout << ans << endl;
  }
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  // cout << flush;
  return 0;
}