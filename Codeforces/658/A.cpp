#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  cin >> n >> m;
  set<ll> A;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    A.insert(a);
  }
  ll ans = -1;
  for (int i = 0; i < m; i++)
  {
    ll b;
    cin >> b;
    if (A.find(b) != A.end()){
      ans = b;
    }
  }
  if (ans == -1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    cout << 1 << " " << ans << endl;
  }
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