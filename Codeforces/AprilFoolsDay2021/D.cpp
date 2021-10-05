#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve()
{
  ll N,M;
  cin >> N >> M;
  if ( (N>>1) & M){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  return 0;
}