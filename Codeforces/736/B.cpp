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
  scanf("%lld",&n);
  string s;
  string t;
  cin >> s;
  cin >> t;
  ll ans = 0;
  for(int i = 0;i < n;i++){
    if (s[i] == '0'){
      if (t[i] == '1'){
        ans++;
        t[i] = '0';
      }
    }else if (s[i] == '1'){
      if (i-1 >=0 && t[i-1] == '1'){
        ans++;
        t[i-1] = '0';
      }else if(i+1 < n && t[i+1] == '1'){
        ans++;
        t[i+1] = '0';
      }
    }
  }
  cout << ans << "\n";
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