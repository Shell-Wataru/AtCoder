#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll a,b,c;
  cin >> a >>b >> c;
  ll aa = abs(a-1);
  ll bb = abs(b-c)+abs(c-1);
  if (aa < bb){
    cout << 1;
  }else if (aa > bb){
    cout << 2;
  }else{
    cout << 3;
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