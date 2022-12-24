#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  deque<pair<char,ll>> runlength_s;
  deque<pair<char,ll>> runlength_t;
  ll t_ones = 0;
  ll s_ones = 0;
  for(auto c:s){
    if (c == '1'){
      s_ones++;
    }
    if(runlength_s.empty() || runlength_s.back().first != c){
      runlength_s.push_back({c,1});
    }else{
      runlength_s.back().second++;
    }
  }
  for(auto c:t){
    if (c == '1'){
      t_ones++;
    }
    if(runlength_t.empty() || runlength_t.back().first != c){
      runlength_t.push_back({c,1});
    }else{
      runlength_t.back().second++;
    }
  }
  if (!(runlength_s.size() == runlength_t.size() && s[0] == t[0])){
    cout << -1 << "\n";
    return 0;
  }
  ll ans = 0;
  for(int i = 0;i < runlength_s.size()-1;i++){
    ll d = abs(runlength_s[i].second-runlength_t[i].second);
    ans += d;
    if (runlength_s[i].second < runlength_t[i].second){
      runlength_s[i].second+=d;
      runlength_s[i+1].second-=d;
    }else{
      runlength_t[i].second+=d;
      runlength_t[i+1].second-=d;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
