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
  string s;
  cin >> s;
  set<char> used;
  ll ans = 0;
  for(auto c:s){
    if (used.count(c) == 1){
      continue;
    }else if (used.size() == 3){
      ans++;
      used.clear();
      used.insert(c);
    }else{
      used.insert(c);
    }
  }
  ans++;
  cout << ans << endl;
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