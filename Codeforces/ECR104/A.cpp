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
  cin >> n;
  vector<ll> level_counts(100,0);
  for(int i = 0 ;i < n;i++){
    ll a;
    cin >> a;
    a--;
    level_counts[a]++;
  }
  for(int i = 0 ;i < 100;i++){
    if (level_counts[i] > 0){
      cout << n - level_counts[i] << "\n";
      return 0;
    }
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