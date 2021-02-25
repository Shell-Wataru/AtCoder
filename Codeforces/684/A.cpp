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
  ll n,c0,c1,h;
  string s;
  cin >> n >> c0 >> c1 >> h;
  cin >> s;
  ll ans = 0;
  for(auto c: s){
    if (c == '0'){
      ans += min(c0, c1 + h);
    }else {
      ans += min(c1, c0 + h);
    }
  }
  cout << ans << endl;
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
  return 0;
}