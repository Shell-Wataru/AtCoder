#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n,x,y;
  cin >> n >> x >> y;
  if (x > y){
    swap(x,y);
  }
  if (x != 0){
    cout << -1 << endl;
  }else if (y == 0){
    cout << -1 << endl;
  }else if ((n-1)% y != 0){
    cout << -1 << endl;
  }else{
    ll last_one = -1;
    for(int i  = 0;i < n-1;i++){
      if (i % y == 0){
        last_one = i+1;
      }
      cout << last_one + 1 << " ";
    }
    cout << endl;
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
  cout << flush;
  return 0;
}