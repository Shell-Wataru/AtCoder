#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string s;
  cin >> s;
  vector<bool> found1(26,false);
  vector<vector<bool>> found2(26,vector<bool>(26,false));
  vector<vector<vector<bool>>> found3(26,vector<vector<bool>>(26,vector<bool>(26,false)));
  for(int i = 0;i < n;i++){
    found1[s[i]-'a'] = true;
  }

  for(int i = 1;i < n;i++){
    found2[s[i-1]-'a'][s[i]-'a'] = true;
  }

  for(int i = 2;i < n;i++){
    found3[s[i-2]-'a'][s[i-1]-'a'][s[i]-'a'] = true;
  }
  for(int i = 0;i < 26;i++){
    if (!found1[i]){
      cout << (char)('a' + i) << "\n";
      return 0;
    }
  }

  for(int i = 0;i < 26;i++){
    for(int j = 0;j  < 26 ;j++){
      if (!found2[i][j]){
        cout << (char)('a' + i) << (char)('a' + j) << "\n";
        return 0;
      }
    }
  }

  for(int i = 0;i < 26;i++){
    for(int j = 0;j  < 26 ;j++){
      for(int k = 0;k  < 26 ;k++){
        if (!found3[i][j][k]){
          cout << (char)('a' + i) << (char)('a' + j) << (char)('a' + k) << "\n";
          return 0;
        }
      }
    }
  }
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}