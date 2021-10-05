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
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  for(int i = 0;i < q;i++){
    ll l,r;
    cin >> l >> r;
    l--;
    r--;
    bool found = false;
    for(int i = 0;i < l;i++){
      if (s[i] == s[l]){
        found = true;
      }
    }
    for(int i = r+1;i < n;i++){
      if (s[i] == s[r]){
        found = true;
      }
    }
    if (found){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
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
  return 0;
}