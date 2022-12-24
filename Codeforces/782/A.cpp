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
  ll n,r,b;
  scanf("%lld", &n);
  scanf("%lld", &r);
  scanf("%lld", &b);
  ll space = b+1;
  for(int i = 0;i <= b;i++){
    if (i != 0){
      cout << "B";
    }
    if (i < r % space){
      cout << string(r/space + 1,'R');
    }else{
      cout << string(r/space,'R');
    }
  }
  cout << "\n";
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