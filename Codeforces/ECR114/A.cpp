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
  for(int i = 0;i < n;i++){
    for(int j = 0;j < i;j++){
      cout << "()";
    }
    for(int j = i;j < n;j++){
      cout << "(";
    }
    for(int j = i;j < n;j++){
      cout << ")";
    }
    cout << "\n";
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