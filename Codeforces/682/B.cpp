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
  ll n;
  cin >> n;
  bool can = false;
  set<ll> s;
  for(int i = 0;i < n;i++){
    ll b;
    cin >> b;
    if (s.find(b) != s.end()){
      can = true;
    }
    s.insert(b);
  }
  if (can){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
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
