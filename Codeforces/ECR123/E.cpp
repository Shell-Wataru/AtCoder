#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  ll x = 1;
  ll y = 1;
  for (auto c : S)
  {
    if (c == 'D')
    {
      x++;
    }
    else
    {
      y++;
    }
  }
  ll move_downs = n - x;
  ll move_rights = n - y;
  // cout << move_downs << "," << move_rights << endl;
  bool have_down = false;
  bool have_right = false;
  ll ans = 1;
  if (S[0] == 'D'){
    ans += move_downs;
  }else{
    ans += move_rights;
  }
  for(auto c:S){
    if (c == 'D')
    {
      have_down = true;
    }
    else
    {
      have_right = true;
    }
    if (have_down && have_right){
      if (c == 'D')
      {
        ans += move_rights + 1;
      }
      else
      {
        ans += move_downs + 1;
      }
    }else{
      ans++;
    }
  }
  if (have_down && have_right){
    if (S[0] == 'D'){
      ans += (move_downs+1) * move_rights;
    }else{
      ans += move_downs * (move_rights+1);
    }
  }
  cout << ans << "\n";
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
  cout << flush;
  return 0;
}