#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  // cin >> n;
  string s;
  cin >> s;
  n = s.length();
  for (size_t i = 0; i < n; i++)
  {
    if (i % 2 == 0){
      if (s[i] == 'a'){
        s[i]= 'b';
      }else{
        s[i]= 'a';
      }
    }else{
      if (s[i] == 'z'){
        s[i]= 'y';
      }else{
        s[i]= 'z';
      }
    }
  }
  cout << s << "\n";
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