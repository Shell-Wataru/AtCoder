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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

set<ll> squareables;

int solve()
{
  ll n;
  cin >> n;
  if (squareables.find(n) != squareables.end()){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
  return 0;
}
int main()
{
  for(int i = 1;i * i <= BASE_NUM;i++){
    squareables.insert(i*i * 2);
    squareables.insert(i*i * 4);
  }
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
