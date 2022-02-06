#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll a,b,c;
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &c);
  ll diff = 0;
  diff = 3*(c % 2);
  if (diff == 0){
    if (b % 2 == 1){
      diff = 2;
    }else{
      diff = 0;
    }
  }else{
    if (b == 0){
    }else{
      diff = 1;
    }
  }
  ll sub = min(a,diff);
  diff -= sub;
  a -= sub;
  if (diff == 0){
    cout << a % 2  << "\n";
  }else{
    cout << diff << "\n";
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