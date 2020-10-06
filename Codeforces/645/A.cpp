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
  ll n,x;
  cin >> n >> x;
  ll odds = 0;
  ll even = 0;
  for(int i = 0;i < n;i++){
    ll a;
    cin >> a;
    if(a % 2 == 0){
      even++;
    }else{
      odds++;
    }
  }
  if (odds == 0){
    cout << "No" << endl;
    return 0;
  }

  if (odds % 2 == 0 && odds > 0){
    if (x % 2 == 0){
      x -= min(x - 1,odds - 1);
    }else{
      x -= min(x,odds - 1);
    }
  }else if(odds % 2 == 1){
    if (x % 2 == 0){
      x -= min(x - 1,odds);
    }else{
      x -= min(x,odds);
    }
  }
  x -= min(x,even);
  if (x == 0){
    cout << "Yes" <<endl;
  }else{
    cout << "No" << endl;
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