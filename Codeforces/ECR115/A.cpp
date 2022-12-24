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
  ll n;
  scanf("%lld",&n);
  string X,Y;
  cin >> X >> Y;
  for(int i = 0;i < n;i++){
    if (X[i] == '1' && Y[i] == '1'){
      cout << "NO\n" ;
      return 0;
    }
  }
  cout << "YES\n";
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