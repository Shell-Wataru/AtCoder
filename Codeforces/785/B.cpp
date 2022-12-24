#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  string S;
  cin >> S;
  vector<bool> used(26,false);
  string patterns;
  for(auto c:S){
    if (used[c-'a']){
      break;
    }else{
      used[c-'a'] = true;
      patterns.push_back(c);
    }
  }
  ll m = patterns.size();
  for(int i = 0;i < S.size();i++){
    if (patterns[i%m] != S[i]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
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