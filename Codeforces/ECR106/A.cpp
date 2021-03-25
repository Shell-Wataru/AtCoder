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
  ll n,k1,k2,w,b;
  cin >> n >> k1 >> k2 >> w >> b;
  ll whites =  min(k1,k2) + abs(k1-k2)/2;
  ll blacks =  min(n- k1,n - k2) + abs(k1-k2)/2;
  if (w <= whites && b <= blacks){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
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
  cout << flush;
  return 0;
}