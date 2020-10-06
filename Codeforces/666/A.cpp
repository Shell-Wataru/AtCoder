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
  vector<string> S(n);
  map<char,ll> counts;
  for (size_t i = 0; i < n; i++)
  {
    cin >> S[i];
  }

  for(int i = 0;i < n;i++){
    for(auto &c:S[i]){
      counts[c]++;
    }
  }
  bool can_make = true;
  for(auto &p:counts){
    if (p.second % n != 0){
      can_make = false;
    }
  }
  if (can_make){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
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