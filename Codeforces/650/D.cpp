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
  int  m;
  string S;
  cin >> S;
  cin >> m;
  vector<ll> b(m);
  vector<ll> ans(m,-1);
  vector<ll> char_count(26,0);
  for(int i = 0;i < m;i++){
    cin >> b[i];
  }
  for(auto c:S){
    char_count[c- 'a']++;
  }
  ll char_index = 25;
  while(char_index >= 0){
    vector<ll> next_indexes;
    for(int i = 0;i < m;i++){
      if (ans[i] != -1){
        continue;
      }
      ll point = 0;
      for(int j = 0;j < m;j++){
        if(ans[j] != -1){
          point += abs(i-j);
        }
      }
      // cout << point << ",";
      if (point == b[i]){
        next_indexes.push_back(i);
      }
    }
    // cout << endl;
    while(next_indexes.size() > char_count[char_index]){{
      char_index--;
    }}
    // cout << char_index << endl;
    // cout << next_indexes.size() << endl;
    for(auto i:next_indexes){
      ans[i] = char_index;
    }
    char_index--;
  }
  for(auto char_index:ans){
    cout << (char)('a' + char_index);
  }
  cout << endl;
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