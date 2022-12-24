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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  ll index = s.size()-1;
  while(index >= 0){
    if(s[index] == '0'){
      t += 'a' + (stoll(s.substr(index-2,2)))-1;
      index -= 3;
    }else{
      t += 'a' + (stoll(s.substr(index,1)))-1;
      index--;
    }
  }
  reverse(t.begin(),t.end());
  cout << t << "\n";
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