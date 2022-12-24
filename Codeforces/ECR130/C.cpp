#define _USE_MATH_DEFINES
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
  ll n;
  cin >> n;
  string s;
  string t;
  cin >> s >> t;
  deque<pair<char,ll>> s_runlength;
  deque<pair<char,ll>> t_runlength;
  for(int i = 0;i < n;i++){
    if (s_runlength.empty() || s_runlength.back().first != s[i]){
      s_runlength.emplace_back(s[i],1);
    }else{
      s_runlength.back().second++;
    }
    if (t_runlength.empty() || t_runlength.back().first != t[i]){
      t_runlength.emplace_back(t[i],1);
    }else{
      t_runlength.back().second++;
    }
    while(!s_runlength.empty() && !t_runlength.empty()){
      if (s_runlength.front().first == t_runlength.front().first){
        // cout << s_runlength[0].first << endl;
        ll l = min(s_runlength.front().second,t_runlength.front().second);
        s_runlength.front().second -= l;
        t_runlength.front().second -= l;
        if (s_runlength[0].second == 0){
          s_runlength.pop_front();
        }
        if (t_runlength[0].second == 0){
          t_runlength.pop_front();
        }
      }else if (s_runlength.size() >= 2 && s_runlength[0].first == 'a' && s_runlength[1].first == 'b' && t_runlength[0].first == 'b'){
        swap(s_runlength[0],s_runlength[1]);
      }else if (s_runlength.size() >= 2 && s_runlength[0].first == 'b' && s_runlength[1].first == 'c' && t_runlength[0].first == 'c'){
        swap(s_runlength[0],s_runlength[1]);
      }else{
        break;
      }
    }
  }
  if (s_runlength.size() == 0 && t_runlength.size() == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
int main()
{
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
